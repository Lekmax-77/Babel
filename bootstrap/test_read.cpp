#include <iostream>
#include <fstream>
#include <portaudio.h>
#include <vector>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024

int main() {
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "Error initializing PortAudio: " << Pa_GetErrorText(err) << std::endl;
        return -1;
    }

    PaStream *stream;
    err = Pa_OpenDefaultStream(&stream, 0, 1, paInt16, SAMPLE_RATE, FRAMES_PER_BUFFER, nullptr, nullptr);
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

    // Lire les données audio depuis le fichier
    std::ifstream inputFile("enregistrement_audio.raw", std::ios::binary);
    if (inputFile.is_open()) {
        std::vector<unsigned char> audioData((std::istreambuf_iterator<char>(inputFile)),
                                             std::istreambuf_iterator<char>());
        inputFile.close();

        std::cout << "Playing..." << std::endl;
        err = Pa_WriteStream(stream, audioData.data(), audioData.size() / 2);  // Divide by 2 for paInt16
        if (err != paNoError) {
            std::cerr << "Error writing stream: " << Pa_GetErrorText(err) << std::endl;
        }

        Pa_Sleep(audioData.size() / (2 * SAMPLE_RATE));  // Sleep for the duration of the audio

        std::cout << "Playback complete." << std::endl;
    } else {
        std::cerr << "Error opening file for reading." << std::endl;
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
