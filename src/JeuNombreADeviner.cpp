/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.cpp
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient le code des fonctions du jeu
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
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : string_un_nom
// Param�tres de sortie : TJoueur
// Param�tres d'entr�e/sortie : &joueurAcreer

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom; //initialisation du nom du joueur
    joueurAcreer.nbPartiesJouees = 0; //r�initialisation des parties jou�es
    joueurAcreer.nbPartiesGagnees = 0; //r�initialisation des parties gagn�es
    joueurAcreer.nbTentatives = 0; //r�initialisation des tentatives
}


// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

int TirerNombreMystere()
{
    srand (time(NULL));
    int nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}


// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: &un_joueur
// Param�tres de sortie: TJoueur, int nombreADeviner

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
                (cout<< "Felicitation! Tu as trouv� le nombre mystere!\n");
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
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: bool gagne, int nbEssais
// Param�tres d'entr�e/sortie : TJoueur &joueur

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
   // A COMPLETER
}

// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: TJoueur joueur
// Param�tres de sortie: int &nbsucces, int &nbechec, int & nbessais

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    // A COMPLETER
}

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur

string Nom(TJoueur joueur){

    return joueur.nom;
}

