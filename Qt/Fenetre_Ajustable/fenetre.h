#ifndef FENETRE_H
#define FENETRE_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QLCDNumber>
#include <QProgressBar>

class Fenetre : public QWidget
{
    Q_OBJECT

private :
    QSlider *m_sliderH;
    QSlider *m_sliderL;

    int m_largeur;
    int m_hauteur;

public :
    Fenetre();

public slots :
    void changerLargeur(int largeur);
    void changerHauteur(int hauteur);

signals :
    void agrandissementMax();
};

#endif
