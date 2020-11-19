#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "header.h"


//////////TABLEAUX//////////

//LIT UN TABLEAU DE STRING
void lectureTableauDynamique(std::vector<std::string>const& table)
{
    int taille(table.size());
    int i(0);

    for (i = 0; i < taille; i++)
    {
        std::cout << table[i] << std::endl;
    }
}

//ECRIT DANS UN TABLEAU DE STRING
void ecritureTableauDynamique(std::vector<std::string>& table)
{
    int nCase(0);
    int taille(table.size());
    std::string phrase(" ");

    std::cout << "quelle case ?" << std::endl;
    std::cin >> nCase; std::cin.ignore(); nCase;
    
    while (nCase > taille)
    {  
        table.push_back("");
        taille = table.size();
    }

    std::getline(std::cin, phrase);
    nCase--;
    table[nCase] = phrase;
}

//LIT UN TABLEAU DYNAMIQUE MULTI-DIMENTIONEL
void lectureTableauDynamiqueMultidimentionel(std::vector<std::vector<int>> grille)
{
    int i(0), j(0);
    int tailleX(grille.size());
    int tailleY(0);
    
    for (i = 0; i < tailleX; i++)
    {
        tailleY = grille[i].size();
        
        for (j = 0; j < tailleY; j++)
        {
            std::cout << grille[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


//////////FICHIER//////////

//écrit dans un fichier
void ecrire()
{
    std::string fichier("C:/Users/Joris/Documents/1.programmation/Cpp/test/score.txt");
    std::string phrase("");
    std::ofstream flux(fichier.c_str());

    std::cout << "Entrez une phrase, tapez END pour finir" << std::endl;
    while(phrase != "END")
    {
        getline(std::cin, phrase);
        if (phrase != "END")
            flux << phrase << std::endl;
    }
}

//lit un fichier
void lecture()
{
    std::string fichier("C:/Users/Joris/Documents/1.programmation/Cpp/test/score.txt");
    std::string phrase("");
    std::ifstream flux(fichier.c_str());

    while(getline(flux, phrase))
    {
        std::cout << phrase << std::endl;
    } 
}


//////////TP//////////

int motMystere()
{
    bool recommencer (0);
    do
    {
        std::string motChoisi(""); //mot choisi pour être mélanger et donc supprimer
        std::string motChoisi2(""); //même que motChoisi mais n'est pas supprimé et sert donc à la vérification
        std::string motMelange(""); //mot à la fin du mélange
        std::string motJoueur2(""); //mot que le joueur propose
        int nbrAleatoire(0);
        int nombreCoup(5);
        int nombreJoueur(0);
        int taille(0); //taille du mot choisi
        int i(0), j(0), k(0); //variable de boucle
        
        srand(time(0));

    //choisi un mot
        std::cout << "Entre le nombre de joueur(s) (1 ou 2)" << std::endl;
        std::cin >> nombreJoueur; std::cin.ignore();

        //si il y a un joueur
        if(nombreJoueur == 2)
        {
        std::cout << "Entrez un mot : " << std::endl;
        std::cin >> motChoisi; std::cin.ignore();
        motChoisi2 = motChoisi;
        }
        //si il y a deux joueurs
        else if (nombreJoueur == 1)
        {
            std::ifstream dico("C:/Users/joris/Documents/1.Programmation/Cpp/test/dico.txt");
            nbrAleatoire = rand() % 22741;
            for (i = 0; i < nbrAleatoire; i++)
            {
                getline(dico, motChoisi);
            }
            motChoisi2 = motChoisi;
        }
        else
        {
            return 0;
        }
        

    //melange le mot
        taille = motChoisi.size();
        k = (taille);
        for (j = 0; j < taille; j++)
        {
            nbrAleatoire = rand() % (k);
            motMelange += motChoisi[nbrAleatoire];
            motChoisi.erase(nbrAleatoire, 1);
            k--;
        }
        
    //verifie le mot joueur 2
        while (motChoisi2 != motJoueur2 && nombreCoup)
        {
            std::cout << "Il reste " << nombreCoup << " coup(s)." << std::endl << "Quel est ce mot ? " << motMelange << std::endl;
            std::cin >> motJoueur2; std::cin.ignore();
            nombreCoup--;
        }
        if(nombreCoup > 0)
            std::cout << "Bien joue a toi" << std::endl << "Veut tu recommencer ? Appuie sur 1" << std::endl;
        else
            std::cout << "Dommage" << std::endl << "Veut tu recommencer ? Appuie sur 1" << std::endl;
        
        std::cin >> recommencer; std::cin.ignore();
    } while (recommencer);
    return 0;
}