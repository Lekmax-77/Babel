/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** main
*/

/*
#include <QApplication>
#include <QLabel>
#include <QIcon>
#include <QComboBox>
#include <iostream>
#include "portaudio.h"
#include <opencv2/opencv.hpp>
#include "Audio.hpp"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    Client::Audio audio;

    // Création de la fenêtre principale
    QLabel label_micro("Select Microphone Device");

    // Création d'un menu déroulant
    QComboBox comboBox(&label_micro);
    comboBox.addItem("Option 1");
    comboBox.addItem("Option 2");
    comboBox.addItem("Option 3");

    // Définition de la taille de la fenêtre (largeur x hauteur)
    label_micro.resize(1600, 900);

    // Définition de l'icône de la fenêtre
    label_micro.setWindowIcon(QIcon("../assets/icon.png"));

    // Définition du titre de la fenêtre
    label_micro.setWindowTitle("Babel - Epitech");

    // Affichage de la fenêtre
    label_micro.show();

    // Exécution de la boucle d'événements
    return app.exec();
}



#include <QApplication>
#include <QLabel>
#include <QIcon>
#include <QComboBox>
#include <iostream>
#include "Window.hpp"*/

#include <iostream>
#include <asio.hpp>
#include "Client.hpp"
#include "NetworkManager.hpp"
#include <memory>

int Launch_Client(std::string host, int port)
{
    std::cout << "Launching client on " << host << ":" << port << std::endl;
    try {
        asio::io_context ioContext;
        std::unique_ptr<Client::INetworkManager> client = std::make_unique<Client::AsioNetworkManager>(ioContext, host, port);

        // client.run();
        ioContext.run();
    } catch (const std::exception& e) {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./Babel_Client <host> <port>" << std::endl;
        return 84;
    } else if (atoi(argv[2]) < 0 || atoi(argv[2]) > 65535) {
        std::cerr << "Invalid port" << std::endl;
        return 84;
    } else if (argc  == 2 && std::string(argv[1]) == "-help") {
        std::cout << "USAGE: ./Babel_Client <host> <port>" << std::endl;
        std::cout << "\t<host> is the server ip address" << std::endl;
        std::cout << "\t<port> is the server port number" << std::endl;
        return 0;
    }

    return Launch_Client(argv[1], atoi(argv[2]));
    /*QApplication app(argc, argv);
    Client::Window window;
    window.show();

    return (app.exec());*/
    return 0;
}
