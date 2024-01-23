#include <iostream>
#include "portaudio.h"
#include <opencv2/opencv.hpp>

int main() {
    // Initialiser PortAudio
    PaError err = Pa_Initialize();
    if (err != paNoError) {
        std::cerr << "Erreur lors de l'initialisation de PortAudio : " << Pa_GetErrorText(err) << std::endl;
        return 1;
    }

    // Obtenir le nombre total de périphériques audio
    int numDevices = Pa_GetDeviceCount();
    if (numDevices < 0) {
        std::cerr << "Erreur lors de la récupération du nombre de périphériques : " << Pa_GetErrorText(numDevices) << std::endl;
        Pa_Terminate();
        return 1;
    }

    std::cout << "Liste des périphériques audio d'entrée :" << std::endl;
    for (int i = 0; i < numDevices; ++i) {
        const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(i);
        if (deviceInfo->maxInputChannels > 0) {
            std::cout << "Périphérique d'entrée #" << i << ": " << deviceInfo->name << std::endl;
        }
    }

    std::cout << "\nListe des périphériques audio de sortie :" << std::endl;
    for (int i = 0; i < numDevices; ++i) {
        const PaDeviceInfo* deviceInfo = Pa_GetDeviceInfo(i);
        if (deviceInfo->maxOutputChannels > 0) {
            std::cout << "Périphérique de sortie #" << i << ": " << deviceInfo->name << std::endl;
        }
    }

    // Terminer PortAudio
    Pa_Terminate();

      // Obtenir la liste des dispositifs vidéo (webcams)
    std::vector<cv::VideoCapture> cameras;
    int numCameras = cv::VideoCapture::getBuildInformation().find("videoio_registry").npos != std::string::npos ?
        cv::VideoCapture::getBuildInformation().find("DC1394").npos != std::string::npos ?
        cv::VideoCapture::getBuildInformation().find("GStreamer").npos != std::string::npos ? cv::VideoCapture::getBuildInformation().find("V4L").npos != std::string::npos ? cv::VideoCapture::getBuildInformation().find("AVFoundation").npos != std::string::npos ? cv::VideoCapture::getBuildInformation().find("FFMPEG").npos != std::string::npos ? cv::VideoCapture::getBuildInformation().find("OpenNI").npos != std::string::npos ? cv::VideoCapture::getBuildInformation().find("OpenNI") < cv::VideoCapture::getBuildInformation().find("OpenNI2") ? cv::VideoCapture::getBuildInformation().find("OpenNI") : cv::VideoCapture::getBuildInformation().find("OpenNI2") : std::string::npos : std::string::npos : std::string::npos : std::string::npos : std::string::npos : std::string::npos : std::string::npos : std::string::npos;

    if (numCameras <= 0) {
        std::cerr << "Aucune webcam n'a été détectée." << std::endl;
        return 1;
    }

    std::cout << "Liste des webcams :" << std::endl;
    for (int i = 0; i < numCameras; ++i) {
        std::cout << "Webcam #" << i << std::endl;
    }

    return 0;
}
