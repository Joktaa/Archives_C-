#ifndef DUREE_H_INCLUDED
#define DUREE_H_INCLUDED

#include <string>

class Duree
{
//ATTRIBUTS
     private:
 
    int m_heures;
    int m_minutes;
    int m_secondes;
    
    void afficher(std::ostream &flux) const;
    
    public:
//CONSTRUCTEURS
    Duree(int heures, int minutes, int secondes);
//METHODES
    bool estEgal(Duree const& b) const;
    bool estPlusPetitQue(Duree const& b) const;
    Duree& operator+=(Duree const& b);
    friend std::ostream& operator<<(std::ostream &flux, Duree const& duree);
};

bool operator==(Duree const& a, Duree const& b);
bool operator<(Duree const& a, Duree const& b);
Duree operator+(Duree const& a, Duree const& b);
std::ostream& operator<<(std::ostream &flux, Duree const& duree);

#endif