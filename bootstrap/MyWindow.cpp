/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** MyWindow.cpp
*/

#include "MyWindow.hpp"

namespace Babel::Client::GUI
{
    MyWindow::MyWindow(): QWidget()
    {

        setWindowTitle("Babel - Client");
        int window_width = QApplication::desktop()->width();
        int window_height = QApplication::desktop()->height();
        resize(window_width, window_height);
        setWindowIcon(QIcon("assets/icon.png"));
        setStyleSheet("background-color: #2C2F33;");
        QFontDatabase::addApplicationFont("assets/Airfool.otf");

        Port = new QLabel(QApplication::translate("windowlayout", "Port:")); //creation des entree utilisateur host et port
        Port->setFont(QFont("Airfool", 35));
        Port->setStyleSheet("color: white");

        lineEditPort = new QLineEdit();
        lineEditPort->setFont(QFont("Airfool", 35));
        lineEditPort->setStyleSheet("color: #00b3f4;"
                                    "border: 1px solid white;"
                                    "border-radius:30%;"
                                    );

    }

    MyWindow::~MyWindow()
    {
        ;
    }

}