#include "fenetre.h"

Fenetre::Fenetre() : QWidget()
{
    setFixedSize(300, 150);

    chocolatNoir << "Mais qu'est ce que c'est que cette question là ?" << "Le chocolat";

    m_boutonDialogue = new QPushButton("CLIIIIIIQUE", this);
    m_boutonDialogue->move(100, 60);

    //QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(ouvrirDialogue()));
    QObject::connect(m_boutonDialogue, SIGNAL(clicked()), this, SLOT(fichier()));
}

void Fenetre::ouvrirDialogue()
{
    int reponse = QMessageBox::question(this, "LA QUESTION", "Aimes tu le lait ?", QMessageBox::Yes | QMessageBox::No);
    if(reponse == QMessageBox::Yes)
        QMessageBox::information(this, "AH", "c'est bien");
    else if(reponse == QMessageBox::No)
        QMessageBox::information(this, "AH", "Oh zut, tu devrais");
}

void Fenetre::ouvrirSaisieTexte()
{
    bool ok = false;
    QString texte = QInputDialog::getText(this, "mmmmm", "TAPE", QLineEdit::Normal, QString(), &ok);
    if(ok && !texte.isEmpty())
        QMessageBox::information(this, "AH", texte);
    else
        QMessageBox::information(this, "AH", "Tu es nul");
}

void Fenetre::laQuestion()
{
    bool ok = false;
    QString reponse = QInputDialog::getItem(this, "LA question", "Tu préfères le chocolat ou les noirs ?", chocolatNoir, 0, true, &ok);
    if(ok && !reponse.isEmpty() && reponse == chocolatNoir[0])
        QMessageBox::information(this, "MAIS", "C'est vrai ça, mais qu'est ce que c'est que cette honte");
    else if(ok && !reponse.isEmpty() && reponse == chocolatNoir[1])
        QMessageBox::information(this, "MAIS", "Mais, c'est pas très gentil");
    else
        QMessageBox::information(this, "MAIS", "T'ES NUL");
}

void Fenetre::police()
{
    bool ok = false;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok)
        m_boutonDialogue->setFont(font);
}

void Fenetre::fichier()
{
    QString fichier = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "Images (*.png *.gif *.jpg *.jpeg)");
    QMessageBox::information(this, "Fichier", "Vous avez sélectionné :\n" + fichier);
}