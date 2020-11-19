#include <iostream>
#include <string>
#include <vector>
#include "Fraction.h"

using namespace std;

    Fraction::Fraction(int numerateur, int denominateur) : m_numerateur(numerateur), m_denominateur(denominateur)
    {
        simplifier();
    }


    void Fraction::afficher(ostream &flux) const
    {
        flux << m_numerateur << " / " << m_denominateur << endl;
    }

    void Fraction::simplifier()
    {
        if (m_numerateur <= m_denominateur)
        {
            int i(m_numerateur);
            for (i = m_numerateur; i > 0; i--)
            {
                if (m_numerateur%i == 0 && m_denominateur%i ==0)
                {
                    m_numerateur /= i;
                    m_denominateur /= i;
                }
            } 
        }
        else
        {
            int i(m_denominateur);
            for (i = m_denominateur; i > 0; i--)
            {
                if (m_numerateur%i == 0 && m_denominateur%i ==0)
                {
                    m_numerateur /= i;
                    m_denominateur /= i;
                }
            }
        }
    }

    double Fraction::reel() const
    {
        double res(m_numerateur);
        res /= m_denominateur;
        return res;
    }

    bool Fraction::estEgal(Fraction const& b) const
    {
        if(m_numerateur == b.m_numerateur && m_denominateur == b.m_denominateur)
            return true;
        else 
            return false;
    }

    bool Fraction::estPlusPetitQue(Fraction const& b) const
    {
        Fraction copiea(m_numerateur, m_denominateur), copieb(b);
        copiea.m_numerateur *= copieb.m_denominateur;
        copieb.m_numerateur *= copiea.m_denominateur;
        if(copiea.m_numerateur < copieb.m_numerateur)
            return true;
        else
            return false;
    }


    Fraction& Fraction::operator+=(Fraction const& b)
    {
        Fraction copieb(b.m_numerateur, b.m_denominateur);
        
        copieb.m_numerateur *= m_denominateur;
        m_numerateur *= b.m_denominateur;
        m_denominateur *= b.m_denominateur;

        m_numerateur += copieb.m_numerateur;

        return *this;
    }

    Fraction& Fraction::operator*=(Fraction const& b)
    {
        m_numerateur *= b.m_numerateur;
        m_denominateur *= b.m_denominateur;

        return *this;
    }


    Fraction operator+(Fraction const& a, Fraction const& b)
    {
        Fraction copie(a);
        copie += b;
        copie.simplifier();
        return copie;
    }

    Fraction operator*(Fraction const& a, Fraction const& b)
    {
        Fraction copie(a);
        copie *= b;
        copie.simplifier();
        return copie;
    }

    bool operator==(Fraction const& a, Fraction const& b)
    {
        return a.estEgal(b);
    }

    bool operator<(Fraction const& a, Fraction const& b)
    {
        return a.estPlusPetitQue(b);
    }

    bool operator>(Fraction const& a, Fraction const& b)
    {
        if(!a.estPlusPetitQue(b) && !a.estEgal(b))
            return true;
        else
            return false;
        
    }

    ostream& operator<<(ostream &flux, Fraction const& a)
    {
        a.afficher(flux);
        return flux;
    }