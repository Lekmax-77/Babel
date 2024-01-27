/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** Window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_
    #include <QtWidgets/QApplication>
    #include <QWidget>
    #include <QPushButton>
    #include <QLabel>
    #include <QLineEdit>
    #include <QHBoxLayout>
    #include <QDesktopWidget>
    // #include <QTcpSocket>
    #include <QDebug>
    #include <QHostAddress>
    #include <QMessageBox>
    #include <QSlider>
	#include <QObject>
    #include <QInputDialog>
    #include <QFontDatabase>
    #include <QFormLayout>
    #include <QtGui>
    #include <QDialog>
    

#ifdef unix 
    #include <unistd.h>
#endif

namespace Client {
class Window : public QWidget
{
    public:
        Window() : QWidget()
        {
        
        	//QSound::play("../../Client/assets/SoundCo.mp3");

        	//QMediaPlayer *player = new QMediaPlayer;
        	//player->setMedia(QUrl::fromLocalFile("../../Client/assets/SoundCo.mp3"));

        	QPalette palette;
            palette.setBrush(this->backgroundRole(), QBrush(QImage("../../Client/assets/Skype.png")));
            this->setPalette(palette);
        	setWindowTitle(
        		QApplication::translate("Babel client", "Babel client"));
        	int window_width = QApplication::desktop()->width();
        	int window_height = QApplication::desktop()->height();
        	resize(window_width, window_height);
        	QFontDatabase::addApplicationFont("../../Client/assets/Airfool.otf");


        	Port = new QLabel(QApplication::translate("windowlayout", "Port:")); //creation des entree utilisateur host et port
        	Port->setFont(QFont("Airfool", 35));
        	Port->setStyleSheet("color: white");

        	lineEditPort = new QLineEdit();
        	lineEditPort->setFont(QFont("Airfool", 35));
        	lineEditPort->setStyleSheet("color: #00b3f4;""border: 1px solid white;""border-radius:30%;");

        	UserName = new QLabel(QApplication::translate("windowlayout", "Username:")); //creation des entree utilisateur host et port
        	UserName->setFont(QFont("Airfool", 35));
        	UserName->setStyleSheet("color: white");

        	lineUserName = new QLineEdit();
        	lineUserName->setFont(QFont("Airfool", 35));
        	lineUserName->setStyleSheet("color: #00b3f4;""border: 1px solid white;""border-radius:30%;");

        	Password = new QLabel(QApplication::translate("windowlayout", "Password:")); //creation des entree utilisateur host et port
        	Password->setFont(QFont("Airfool", 35));
        	Password->setStyleSheet("color: white");

        	linePassword = new QLineEdit();
        	linePassword->setFont(QFont("Airfool", 35));
        	linePassword->setStyleSheet("color: #00b3f4;""border: 1px solid white;""border-radius:30%;");


        	Host = new QLabel(QApplication::translate("windowlayout", "Host:"));
        	Host->setFont(QFont("Airfool", 35));
        	Host->setStyleSheet("color: white");


        	lineEditHost = new QLineEdit();
        	lineEditHost->setFont(QFont("Airfool", 35));
        	lineEditHost->setStyleSheet("color: #00b3f4;""border: 1px solid white;""border-radius:30%;");

        	QHBoxLayout *layout = new QHBoxLayout(); //layout
        	layout->addWidget(Port);
        	layout->addWidget(lineEditPort);
        	layout->addWidget(UserName);
        	layout->addWidget(lineUserName);
        	layout->addWidget(Password);
        	layout->addWidget(linePassword);
        	layout->addWidget(Host);
        	layout->addWidget(lineEditHost);

        	UserName->setVisible(false);
        	lineUserName->setVisible(false);
        	Password->setVisible(false);
        	linePassword->setVisible(false);

        	setLayout(layout);


        	boutonConnection = new QPushButton("Connect", this);

        	boutonConnection->setGeometry(810, 700, 230, 100);
        	boutonConnection->setFont(QFont("Airfool", 35));
        	boutonConnection->setStyleSheet("background-color: white;""color: #00b3f4;" "border: 1px solid white;" "border-radius:30%;" );
        	boutonConnection->setCursor(Qt::PointingHandCursor);

        	boutonSignIn = new QPushButton("Sign In", this);
        	boutonSignIn->setGeometry(810, 700, 230, 100);
        	boutonSignIn->setFont(QFont("Airfool", 35));
        	boutonSignIn->setStyleSheet("background-color: white;""color: #00b3f4;" "border: 1px solid white;" "border-radius:30%;" );
        	boutonSignIn->setCursor(Qt::PointingHandCursor);

        	boutonContacts = new QPushButton("Add Contact", this);
        	boutonContacts->setGeometry(50, 500, 300, 100);
        	boutonContacts->setFont(QFont("Airfool", 35));
        	boutonContacts->setStyleSheet("background-color: white;""color:#00b3f4 ;" "border: 1px solid white;" "border-radius:30%;" );
        	boutonContacts->setCursor(Qt::PointingHandCursor);


        	boutonSignUp = new QPushButton("Sign Up", this);
        	boutonSignUp->setGeometry(810, 700, 230, 100);
        	boutonSignUp->setFont(QFont("Airfool", 35));
        	boutonSignUp->setStyleSheet("background-color: white;""color: #00b3f4;" "border: 1px solid white;" "border-radius:30%;" );
        	boutonSignUp->setCursor(Qt::PointingHandCursor);

        	boutonCall = new QPushButton("", this);
        	boutonCall->setGeometry(1000, 850, 230, 100);
        	boutonCall->setFont(QFont("Airfool", 35));
        	boutonCall->setStyleSheet("image: url(../../Client/assets/pngegg.png);" "border: 1px solid white;" "border-radius:30%;" );
        	boutonCall->setCursor(Qt::PointingHandCursor);

        	boutonSignIn->setVisible(false);
        	boutonSignUp->setVisible(false);
        	boutonContacts->setVisible(false);
        	boutonCall->setVisible(false);

        	connect(boutonConnection, SIGNAL(clicked()), this, SLOT(connectToServer()));
        	//connect(socket, SIGNAL(bytesWritten(qint64)), this, SLOT(bytesWritten(qint64)));
        }
        ~Window();

    protected:
    private:
};
}

#endif /* !WINDOW_HPP_ */
