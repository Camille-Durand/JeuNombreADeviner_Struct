/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;

#include "../include/JeuNombreADeviner.h"

int main()
{
    string un_nom;
    TJoueur joueurAcreer;

    cout << "-------------------------------------------------------------------------" << endl;
    cout << "Bienvenue dans JeuNombreADeviner! Veuillez ecrire votre nom de joueur: " << endl;
    cin >> un_nom;

    InitJoueur(joueurAcreer, un_nom);
    JouerPartie(joueurAcreer, TirerNombreMystere());
    MajResultatsJoueur(joueurAcreer, joueurAcreer.nbTentatives, joueurAcreer.nbPartiesGagnees);
    ResultatsJoueur(joueurAcreer, joueurAcreer.nbPartiesGagnees, joueurAcreer.nbPartiesJouees, joueurAcreer.nbTentatives);

    cout << "\n \nNombres de tentatives de " << un_nom << ": " << joueurAcreer.nbTentatives << " \nNombres de parties gagnees: " << joueurAcreer.nbPartiesGagnees << endl;
    cout << "-------------------------------------------------------------------------" << endl;

    return 0;
}

