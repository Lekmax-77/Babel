#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QComboBox>
#include <QStringList>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Créer la fenêtre principale
    QWidget window;
    window.setWindowTitle("Menu Déroulant avec Qt");

    // Créer un label
    QLabel *label = new QLabel("Sélectionnez un élément :", &window);

    // Créer un menu déroulant avec une liste prédéfinie
    QComboBox *comboBox = new QComboBox(&window);
    QStringList items;
    items << "Élément 1" << "Élément 2" << "Élément 3";
    comboBox->addItems(items);

    // Connecter un slot à l'événement de changement de sélection du menu déroulant
    QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
                     [=](int index){ qDebug() << "Sélection changée : " << items[index]; });

    // Utiliser un layout pour organiser les éléments
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(label);
    layout->addWidget(comboBox);

    // Afficher la fenêtre
    window.show();

    return app.exec();
}
