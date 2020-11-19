#include <iostream>
#include <string>
#include "Duree.h"

using namespace std;

    Duree::Duree(int heures, int minutes, int secondes)
    {
        m_heures = heures + (minutes / 60);
        m_minutes = (minutes % 60) + (secondes / 60);
        m_secondes = (secondes % 60);
    }

    
    void Duree::afficher(ostream &flux) const
    {
        flux << m_heures << "h" << m_minutes << "m" << m_secondes << "s";
    }
    
    bool Duree::estEgal(Duree const& b) const
    {
        if(b.m_heures == m_heures && b.m_minutes == m_minutes && b.m_secondes == m_secondes)
            return true;
        else 
            return false;
    }

    bool Duree::estPlusPetitQue(Duree const& b) const
    {
        if(m_heures < b.m_heures)
            return true;
        else if(m_heures == b.m_heures && m_minutes < b.m_minutes)
            return true;
        else if(m_heures == b.m_heures && m_minutes == b.m_minutes && m_secondes < b.m_secondes)
            return true;
        else
            return false;
    }

    Duree& Duree::operator+=(Duree const& b)
    {
        m_secondes += b.m_secondes;

        m_minutes += (b.m_minutes + (m_secondes / 60));
        m_secondes %= 60;

        m_heures += (b.m_heures + (m_minutes / 60));
        m_minutes %= 60;
        
        return *this;
    }


    bool operator==(Duree const& a, Duree const& b)
    {
        if(a.estEgal(b))
            return true;
        else 
            return false;
    }

    bool operator<(Duree const& a, Duree const& b)
    {
        return a.estPlusPetitQue(b);
    }

    Duree operator+(Duree const& a, Duree const& b)
    {
        Duree copie(a);
        copie += b;
        return copie;
    }

    ostream& operator<<(ostream &flux, Duree const& duree)
    {
        duree.afficher(flux);
        return flux;
    }