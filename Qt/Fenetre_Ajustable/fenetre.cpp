#include "fenetre.h"

Fenetre::Fenetre() : QWidget(), m_largeur(300), m_hauteur(170)
{
    setFixedSize(m_largeur, m_hauteur);

    m_sliderH = new QSlider(Qt::Vertical, this);
    m_sliderH->setRange(170, 300);
    m_sliderH->setGeometry(225, 10, 20, 150);

    m_sliderL = new QSlider(Qt::Horizontal, this);
    m_sliderL ->setRange(300, 600);
    m_sliderL -> setGeometry(10, 60, 150, 20);

    QObject::connect(m_sliderL, SIGNAL(valueChanged(int)), this, SLOT(changerLargeur(int)));
    QObject::connect(m_sliderH, SIGNAL(valueChanged(int)), this, SLOT(changerHauteur(int)));
    QObject::connect(this, SIGNAL(agrandissementMax()), qApp, SLOT(quit()));
}

void Fenetre::changerLargeur(int largeur)
{
    m_largeur = largeur;
    setFixedSize(largeur, m_hauteur);

    if(largeur == m_sliderL->maximum())
        emit agrandissementMax();
}
void Fenetre::changerHauteur(int hauteur)
{
    m_hauteur = hauteur;
    setFixedSize(m_largeur, hauteur);
}