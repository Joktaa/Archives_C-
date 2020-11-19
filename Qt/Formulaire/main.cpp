#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QFormLayout>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget fenetre;

    QLineEdit *age = new QLineEdit;
    QLineEdit *nom = new QLineEdit;
    QLineEdit *chocolatNoir = new QLineEdit;
    QPushButton *quitter = new QPushButton("quitter");

    QVBoxLayout *mainLayout = new QVBoxLayout;
    QFormLayout *layout = new QFormLayout;

    mainLayout->addLayout(layout);
    mainLayout->addWidget(quitter);

    layout->addRow("age : ", age);
    layout->addRow("nom : ", nom);
    layout->addRow("Tu préfères le chocolat ou les noirs ?", chocolatNoir);

    fenetre.setLayout(mainLayout);
    fenetre.show();

    return app.exec();
}
