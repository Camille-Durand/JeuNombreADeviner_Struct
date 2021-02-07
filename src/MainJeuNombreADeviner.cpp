/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: MainJeuNombreAdeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code jeu
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
    cout << "Bienvenue dans JeuNombreADeviner! Veuillez ecrire votre nom de joueur: " << endl;
    cin >> un_nom;
    InitJoueur(joueurAcreer, un_nom);
    JouerPartie(joueurAcreer, TirerNombreMystere());
    MajResultatsJoueur(joueurAcreer, joueurAcreer.nbTentatives, joueurAcreer.nbPartiesGagnees);
    ResultatsJoueur(joueurAcreer, joueurAcreer.nbPartiesGagnees, joueurAcreer.nbPartiesJouees, joueurAcreer.nbTentatives);
    cout << "Tu as mis " << joueurAcreer.nbTentatives << " tentatives, tu as reussi " << joueurAcreer.nbPartiesGagnees << " parties, et tu as perdu " << joueurAcreer.nbPartiesJouees << " parties.";

    return 0;
}

