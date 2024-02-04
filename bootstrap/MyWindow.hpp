/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** MyWindow.hpp
*/

#ifndef MYWINDOW_HPP_
	#define MYWINDOW_HPP_
#include <QtWidgets/QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QDesktopWidget>
// #include <QTcpSocket>
#include <QDebug>
//#include <QHostAddress>
#include <QMessageBox>
#include <QSlider>
#include <QObject>
#include <QInputDialog>
#include <QFontDatabase>
#include <QFormLayout>
#include <QtGui>
#include <QDialog>
#include <string>
#include <functional>


//#include "Client.hpp"

#ifdef unix
#include <unistd.h>
#endif


namespace Babel::Client::GUI {

    class MyWindow : public QWidget
    {
        Q_OBJECT

        public:
            MyWindow();
            ~MyWindow();

        //private slots:

        private:


        private:
            // add attributes here
            QLabel *Port;
            QLineEdit *lineEditPort;


    };

}
#endif /*MYWINDOW_HPP_*/