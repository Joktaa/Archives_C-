#ifndef FENPRINCIPALE_H
#define FENPRINCIPALE_H

#include <fensecondaire.h>

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QMessageBox>

#include <QTextStream>
#include <QDebug>

/*
Amélioration :
    -Créer le fichier Cpp avec QWidget Tap
    -Enregistrer les fichiers dans un dossier
*/

class FenPrincipale : public QWidget
{
    //Q_OBJECT

private :

//Layouts et GroupBox
    QVBoxLayout *mainLayout;
    QGridLayout *nameLayout;
    QVBoxLayout *optionsLayout;
    QGridLayout *commentsLayout;
    QGroupBox *name;
    QGroupBox *options;
    QGroupBox *comments;


//Widgets
    //Name
    QLineEdit *nom;
    QLineEdit *classeMere;
    QLabel *nomTitle;
    QLabel *classeMereTitle;
    //Options
    QCheckBox *IM;
    QCheckBox *constructeur;
    QCheckBox *destructeur;

    //Commentaires
    QLineEdit *auteur;
    QLineEdit *date;
    QTextEdit *role;
    QLabel *auteurTitle;
    QLabel *dateTitle;
    QLabel *roleTitle;

    //Autre
    QPushButton *generer;
    QPushButton *quitter;


public :
    FenPrincipale();

Q_OBJECT private slots :
    void genere();
};

#endif // FENPRINCIPALE_H
