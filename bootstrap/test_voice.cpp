






#include <iostream>
#include <fstream>
#include <portaudio.h>
#include <vector>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024


int recordCallback(const void* inputBuffer, void* outputBuffer, unsigned long framesPerBuffer, const PaStreamCallbackTimeInfo* timeInfo, PaStreamCallbackFlags statusFlags, void* userData)
{
    AudioController* _record = (AudioController*)userData;
    const float* input = (const float*)inputBuffer;
    unsigned char* audio_data = NULL;
    int _len = 0;

    // NO WARNING
    (void)timeInfo;
    (void)statusFlags;
    (void)outputBuffer;

    _record->getEncoding().encodeAudio(input, &_len, &audio_data);
    _record->setAudioData(audio_data);
    _record->setLen(_len);
    return paContinue;
}

int main() {

























    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "Error initializing PortAudio: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    PaStream *stream;

    PaStreamParameters inputParameters;
    inputParameters.device = Pa_GetDefaultInputDevice();
    inputParameters.channelCount = 2;
    inputParameters.sampleFormat = paFloat32;
    inputParameters.suggestedLatency = Pa_GetDeviceInfo(inputParameters.device)->defaultLowInputLatency;
    inputParameters.hostApiSpecificStreamInfo = nullptr;

    err = Pa_OpenStream(&stream, &inputParameters, nullptr, 24000, 480, paClipOff, nullptr, nullptr);
    
    
    return 0;
    if (err != paNoError) {
        std::cerr << "Error opening stream: " << Pa_GetErrorText(err) << std::endl;
        Pa_Terminate();
        return -1;
    }

    err = Pa_StartStream(stream);
    if (err != paNoError) {
        std::cerr << "Error starting stream: " << Pa_GetErrorText(err) << std::endl;
        Pa_CloseStream(stream);
        Pa_Terminate();
        return -1;
    }

    std::cout << "Recording... Press Enter to stop." << std::endl;


    while (std::cin.get() == '\0') {
        std::vector<unsigned char> audioData(FRAMES_PER_BUFFER * 2);  // 2 bytes per sample (paInt16)

        err = Pa_ReadStream(stream, audioData.data(), FRAMES_PER_BUFFER);
        if (err != paNoError) {
            std::cerr << "Error reading stream: " << Pa_GetErrorText(err) << std::endl;
            break;
        }

        // Enregistrez les données audio dans un fichier
        std::ofstream outputFile("enregistrement_audio.raw", std::ios::binary);
        if (outputFile.is_open()) {
            outputFile.write(reinterpret_cast<const char*>(audioData.data()), audioData.size());
            outputFile.close();
        } else {
            std::cerr << "Error opening file for writing." << std::endl;
        }
    }

    err = Pa_StopStream(stream);
    if (err != paNoError) {
        std::cerr << "Error stopping stream: " << Pa_GetErrorText(err) << std::endl;
    }

    err = Pa_CloseStream(stream);
    if (err != paNoError) {
        std::cerr << "Error closing stream: " << Pa_GetErrorText(err) << std::endl;
    }

    Pa_Terminate();

    return 0;
}
