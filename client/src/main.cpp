/*
** EPITECH PROJECT, 2024
** Babel
** File description:
** main
*/


#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QLabel label("Hello, Qt in VS Code!");
    label.show();

    return app.exec();
}
