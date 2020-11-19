#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <string>

class Fraction
{
//ATTRIBUTS
    int m_numerateur;
    int m_denominateur;

public :
//CONSTRUCTEURS
    Fraction(int numerateur = 0, int denominateur = 1);

//METHODES
    void afficher(std::ostream &flux) const;
    void simplifier();
    double reel() const;
    bool estEgal(Fraction const& b) const;
    bool estPlusPetitQue(Fraction const& b) const;
    Fraction& operator+=(Fraction const& b);
    Fraction& operator*=(Fraction const& b);
};

    Fraction operator+(Fraction const& a, Fraction const& b);
    Fraction operator*(Fraction const& a, Fraction const& b);
    bool operator==(Fraction const& a, Fraction const& b);
    bool operator<(Fraction const& a, Fraction const& b);
    bool operator>(Fraction const& a, Fraction const& b);
    std::ostream& operator<<(std::ostream &flux, Fraction const& a);

#endif