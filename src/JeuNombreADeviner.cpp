/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient le code des fonctions du jeu
// Nom des composants utilises: JeuNombreADeviner.h
//                              iostream
//                              ctime
// Historique du fichier:
/*************************************************/
#include <iostream>
using namespace std;
#include "../include/JeuNombreAdeviner.h"
#include <time.h>

// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : string_un_nom
// Paramètres de sortie : TJoueur
// Paramètres d'entrée/sortie : &joueurAcreer

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom; //initialisation du nom du joueur
    joueurAcreer.nbPartiesJouees = 0; //réinitialisation des parties jouées
    joueurAcreer.nbPartiesGagnees = 0; //réinitialisation des parties gagnées
    joueurAcreer.nbTentatives = 0; //réinitialisation des tentatives
}


// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

int TirerNombreMystere()
{
    srand (time(NULL));
    int nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}


// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: &un_joueur
// Paramètres de sortie: TJoueur, int nombreADeviner

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    {
        int nombre_ecrit;
        int i;
        nombre_ecrit = -1;
        while (i<5)
        {
            cout << "Devinez le nombre mystere, qui est entre 1 & 10: \n";
            cin >> nombre_ecrit;
            if (nombre_ecrit==nombreADeviner)
            {
                (cout<< "Felicitation! Tu as trouvé le nombre mystere!\n");
                un_joueur.nbPartiesJouees++;
                un_joueur.nbPartiesGagnees++;
                un_joueur.nbTentatives=un_joueur.nbTentatives+i;
            }
            if (nombre_ecrit >= nombreADeviner)
            {
                (cout << "Plus petit: \n");
                i++;
            }
            if (nombre_ecrit <= nombreADeviner)
            {
                (cout << "Plus grand: \n");
                i++;
            }
        }
        if (i==5)
        {
            cout << "Tu as perdu...\n";
            un_joueur.nbPartiesJouees++;
            un_joueur.nbTentatives=un_joueur.nbTentatives + i;
        }
    }
}


// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: bool gagne, int nbEssais
// Paramètres d'entrée/sortie : TJoueur &joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   // A COMPLETER
}

// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: TJoueur joueur
// Paramètres de sortie: int &nbsucces, int &nbechec, int & nbessais

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    // A COMPLETER
}

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

