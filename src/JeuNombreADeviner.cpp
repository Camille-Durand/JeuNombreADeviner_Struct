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

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom; //initialisation du nom du joueur
    joueurAcreer.nbPartiesJouees = 0; //r�initialisation des parties jou�es
    joueurAcreer.nbPartiesGagnees = 0; //r�initialisation des parties gagn�es
    joueurAcreer.nbTentatives = 0; //r�initialisation des tentatives
}
// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : string_un_nom
// Param�tres de sortie : TJoueur
// Param�tres d'entr�e/sortie : &joueurAcreer

int TirerNombreMystere()
{
    srand (time(NULL));
    int nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}
// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nombre_ecrit = 0; //nombre �crit par le joueur
    int i = 0; //nombre de tentatives
    while (i<5) //tant que le joueur ne d�passe pas ne nombre de tentative
    {
        cout << "Devinez le nombre mystere, qui est entre 1 & 10: \n"; //affichage de la demande
        cin >> nombre_ecrit; //r�cup�ration d'un nombre �crit par le joueur
        if (nombre_ecrit==nombreADeviner) //le joueur trouve le nombre
        {
            (cout<< "Felicitation! Tu as trouve le nombre mystere! Rejoue jusqu'a une defaite.\n");
            MajResultatsJoueur(un_joueur, i+1, true); //nom du joueur, nombre de tentative, victoire en true
            i = 0;
        }
        else if (nombre_ecrit >= nombreADeviner) //si le nombre est sup�rieur au nombre myst�re
        {
            (cout << "Plus petit: \n");
            i++; //nombre de tentative +1
        }
        else if (nombre_ecrit <= nombreADeviner) //si le nombre est inf�rieur au nombre myst�re
        {
            (cout << "Plus grand: \n");
            i++; //nombre de tentative +1
        }
    }
    if (i==5) //le joueur ici d�passe le nombre de tentative
    {
        cout << "Fini!";
        MajResultatsJoueur(un_joueur,5,false); //nom du joueur, nombre de tentative = 10, victoire en false = d�faite
    }
}
// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: &un_joueur
// Param�tres de sortie: TJoueur, int nombreADeviner

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
    joueur.nbTentatives = nbEssais + joueur.nbTentatives;

    if (gagne = true)
    {
        joueur.nbPartiesGagnees = joueur.nbPartiesGagnees + 1;
    }
}
// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: bool gagne, int nbEssais
// Param�tres d'entr�e/sortie : TJoueur &joueur

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees/2;
    nbechec = (joueur.nbPartiesJouees - joueur.nbPartiesGagnees)/2;
    nbessais = joueur.nbTentatives/2;
}
// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: TJoueur joueur
// Param�tres de sortie: int &nbsucces, int &nbechec, int & nbessais

string Nom(TJoueur joueur){

    return joueur.nom;
}
// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur
