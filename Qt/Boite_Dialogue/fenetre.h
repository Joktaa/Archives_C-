#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QFontDialog>
#include <QFileDialog>

class Fenetre : public QWidget
{
    Q_OBJECT

private :
    QPushButton *m_boutonDialogue;
    QStringList chocolatNoir;

public :
    Fenetre();

public slots :
    void ouvrirDialogue();
    void ouvrirSaisieTexte();
    void laQuestion();
    void police();
    void fichier();
};

#endif