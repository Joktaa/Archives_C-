#ifndef PERSONNAGE_H_INCLUDED
#define PERSONNAGE_H_INCLUDED

#include <string>
#include "Arme.h"

class Personnage
{
//ATTRIBUTS
private:

    int m_vie;
    int m_mana;
    Arme *m_arme;


public:
//CONSTRUCTEURS
    Personnage();
    Personnage(std::string nomArme, int degatsArme);
    Personnage(Personnage const& autre);
//DESTRUCTEURS
    ~Personnage();
//METHODES
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;
    void afficherEtat() const;
    Personnage& operator=(Personnage const& autre);
};

#endif