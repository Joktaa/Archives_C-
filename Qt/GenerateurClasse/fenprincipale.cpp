#include "fenprincipale.h"

FenPrincipale::FenPrincipale() : QWidget()
{
    setFixedSize(400, 600);

//Création des layouts et groupBox
    mainLayout = new QVBoxLayout;
    nameLayout = new QGridLayout;
    commentsLayout = new QGridLayout;
    optionsLayout = new QVBoxLayout;
    name = new QGroupBox("Nom");
    options = new QGroupBox("Options");
    comments = new QGroupBox("Commentaires");

//Création des widgets
    //Name
    nom = new QLineEdit;
    classeMere = new QLineEdit;
    nomTitle = new QLabel("Nom : ");
    classeMereTitle = new QLabel("Classe mère : ");

    //Option
    IM = new QCheckBox;
        IM->setText("Protéger le header contre les inclusions multiples");
    constructeur = new QCheckBox;
        constructeur->setText("Génerer un constructeur par défaut");
    destructeur = new QCheckBox;
        destructeur->setText("Génerer un destructeur");

    //Commentaires
    auteur = new QLineEdit;
    date = new QLineEdit;
    role = new QTextEdit;
    auteurTitle = new QLabel("Auteur : ");
    dateTitle = new QLabel("Date de création : ");
    roleTitle = new QLabel("Role de la classe : ");

    //Autre
    generer = new QPushButton("Générer");
    quitter = new QPushButton("Quitter");


//Ajout des Widgets
    nameLayout->addWidget(nomTitle, 0, 0, 1, 1);
    nameLayout->addWidget(nom, 0, 1, 1, 3);
    nameLayout->addWidget(classeMereTitle, 1, 0, 1, 1);
    nameLayout->addWidget(classeMere, 1, 1, 1, 3);

    optionsLayout->addWidget(IM);
    optionsLayout->addWidget(constructeur);
    optionsLayout->addWidget(destructeur);

    commentsLayout->addWidget(auteur, 0, 1, 1, 3);
    commentsLayout->addWidget(date, 1, 1, 1, 3);
    commentsLayout->addWidget(role, 2, 1, 1, 3);
    commentsLayout->addWidget(auteurTitle, 0, 0, 1, 1);
    commentsLayout->addWidget(dateTitle, 1, 0, 1, 1);
    commentsLayout->addWidget(roleTitle, 2, 0, 1, 1);


//Ajout des layouts
    name->setLayout(nameLayout);
    options->setLayout(optionsLayout);
    comments->setLayout(commentsLayout);
    mainLayout->addWidget(name);
    mainLayout->addWidget(options);
    mainLayout->addWidget(comments);
    mainLayout->addWidget(generer);
    mainLayout->addWidget(quitter);
    this->setLayout(mainLayout);

//Connexion
    QObject::connect(quitter, SIGNAL(clicked()), this, SLOT(close()));
    QObject::connect(generer, SIGNAL(clicked()), this, SLOT(genere()));
}

void FenPrincipale::genere()
{
    QString texte;

    if(nom->text().isEmpty())
    {
        QMessageBox::warning(this, "Erreur", "La classe n'a pas de nom");
        return;
    }
//Commentaires
    texte += "/*";
    if(!auteur->text().isEmpty())
        texte += "\nAuteur : " + auteur->text();
    if(!date->text().isEmpty())
        texte += "\nDate : " + date->text();
    if(!role->toPlainText().isEmpty())
        texte += "\nRole : \n" + role->toPlainText();
    texte += "\n*/";

//IM
    if(IM->isChecked())
    {
        texte += "\n\n\n#ifndef HEADER_" + nom->text().toUpper();
        texte += "\n#define HEADER_" + nom->text().toUpper();
    }

//Nom
    texte += "\n\nclass " + nom->text();
    if(!classeMere->text().isEmpty())
        texte += " : public " + classeMere->text();

//Contenue
    texte += "\n{\n    private : \n\n    public : ";
    if(constructeur->isChecked())
        texte += "\n        " + nom->text() + "();";
    if(destructeur->isChecked())
        texte += "\n        ~" + nom->text() + "();";
    texte += "\n}";



    if(IM->isChecked())
        texte += "\n\n#endif";

    QDialog *fenetre = new FenSecondaire(texte);
    fenetre->exec();
}
