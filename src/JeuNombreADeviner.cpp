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

void InitJoueur(TJoueur& joueurAcreer, string un_nom)
{
    joueurAcreer.nom = un_nom; //initialisation du nom du joueur
    joueurAcreer.nbPartiesJouees = 0; //réinitialisation des parties jouées
    joueurAcreer.nbPartiesGagnees = 0; //réinitialisation des parties gagnées
    joueurAcreer.nbTentatives = 0; //réinitialisation des tentatives
}
// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : string_un_nom
// Paramètres de sortie : TJoueur
// Paramètres d'entrée/sortie : &joueurAcreer

int TirerNombreMystere()
{
    srand (time(NULL));
    int nombreADeviner = rand() % 10 + 1;
    return nombreADeviner;
}
// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

void JouerPartie(TJoueur& un_joueur, int nombreADeviner)
{
    int nombre_ecrit = 0; //nombre écrit par le joueur
    int i = 0; //nombre de tentatives
    while (i<5) //tant que le joueur ne dépasse pas ne nombre de tentative
    {
        cout << "Devinez le nombre mystere, qui est entre 1 & 10: \n"; //affichage de la demande
        cin >> nombre_ecrit; //récupération d'un nombre écrit par le joueur
        if (nombre_ecrit==nombreADeviner) //le joueur trouve le nombre
        {
            (cout<< "Felicitation! Tu as trouve le nombre mystere! Rejoue jusqu'a une defaite.\n");
            MajResultatsJoueur(un_joueur, i+1, true); //nom du joueur, nombre de tentative, victoire en true
            i = 0;
        }
        else if (nombre_ecrit >= nombreADeviner) //si le nombre est supérieur au nombre mystère
        {
            (cout << "Plus petit: \n");
            i++; //nombre de tentative +1
        }
        else if (nombre_ecrit <= nombreADeviner) //si le nombre est inférieur au nombre mystère
        {
            (cout << "Plus grand: \n");
            i++; //nombre de tentative +1
        }
    }
    if (i==5) //le joueur ici dépasse le nombre de tentative
    {
        cout << "Fini!";
        MajResultatsJoueur(un_joueur,5,false); //nom du joueur, nombre de tentative = 10, victoire en false = défaite
    }
}
// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: &un_joueur
// Paramètres de sortie: TJoueur, int nombreADeviner

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne)
{
    joueur.nbTentatives = nbEssais + joueur.nbTentatives;

    if (gagne = true)
    {
        joueur.nbPartiesGagnees = joueur.nbPartiesGagnees + 1;
    }
}
// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: bool gagne, int nbEssais
// Paramètres d'entrée/sortie : TJoueur &joueur

void ResultatsJoueur(TJoueur joueur, int& nbsucces, int& nbechec, int& nbessais)
{
    nbsucces = joueur.nbPartiesGagnees/2;
    nbechec = (joueur.nbPartiesJouees - joueur.nbPartiesGagnees)/2;
    nbessais = joueur.nbTentatives/2;
}
// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: TJoueur joueur
// Paramètres de sortie: int &nbsucces, int &nbechec, int & nbessais

string Nom(TJoueur joueur){

    return joueur.nom;
}
// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur
