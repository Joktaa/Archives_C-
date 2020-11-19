#include "fensecondaire.h"

FenSecondaire::FenSecondaire(QString texte) : QDialog(), m_texte(texte)
{
    setFixedSize(600, 400);

//Création Layout
    QVBoxLayout *mainLayout = new QVBoxLayout;

//Création Widgets
    QTextEdit *classe = new QTextEdit;
        classe->setText(m_texte);
    QPushButton *quitter = new QPushButton("quitter");

//Ajout Widgets et Layouts
    mainLayout->addWidget(classe);
    mainLayout->addWidget(quitter);
    this->setLayout(mainLayout);

//Connexion
    QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(close()));
}
