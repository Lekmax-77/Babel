#include <iostream>
#include <portaudio.h>
#include <wavefile.h>

#define SAMPLE_RATE 44100
#define FRAMES_PER_BUFFER 1024
#define RECORDING_TIME 5 // en secondes

int main() {
    Pa_Initialize();

    PaStream* stream;
    Pa_OpenDefaultStream(&stream, 1, 0, paInt16, SAMPLE_RATE, FRAMES_PER_BUFFER, nullptr, nullptr);

    Pa_StartStream(stream);

    std::cout << "Enregistrement audio en cours..." << std::endl;

    Pa_Sleep(RECORDING_TIME * 1000); // en millisecondes

    Pa_StopStream(stream);
    Pa_CloseStream(stream);
    Pa_Terminate();

    std::cout << "Enregistrement terminé." << std::endl;

    return 0;
}
