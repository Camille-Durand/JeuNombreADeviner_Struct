/*************************************************/
// Nom du projet: Jeu du nombre à deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de création : 25/01/2021
// Rôle du fichier: Contient la déclaration du type pour représenter un joueur
// et les fonctions concernant le jeu
// Nom des composants utilises: string
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;

//Type: structure TJoueur
// Rôle : représente un joueur. Définit les propriétés d'un joueur.

typedef struct {

string nom;  // nom du joueur
int nbPartiesJouees; // nombre de parties jouées
int nbPartiesGagnees; //nombre de parties gagnées
int nbTentatives; //nombre de tentatives
} TJoueur;

void InitJoueur (TJoueur &joueurAcreer, string un_nom);
// Nom :InitJoueur
// Rôle : Crée un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagnées et de parties jouées seront à 0.
// Paramètres d'entrée : string_un_nom
// Paramètres de sortie : TJoueur
// Paramètres d'entrée/sortie : &joueurAcreer

int TirerNombreMystere();
// Nom :TirerNombreMystere
// Rôle : Tire aléatoirement un nombre à deviner entre 0 et 10
// Valeur de retour : nombre à deviner

void JouerPartie (TJoueur &un_joueur, int nombreADeviner);
// Nom :JouerPartie
// Rôle : Fait jouer une partie au joueur passé en paramètre
//        A la fin, met à jour les informations du joueur
// Paramètres d'entrée: &un_joueur
// Paramètres de sortie: TJoueur, int nombreADeviner

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne);
// Nom : MajResultatsJoueur
// Rôle : met à jour les informations du joueur passé en paramètre
// Paramètres d'entrée: bool gagne, int nbEssais
// Paramètres d'entrée/sortie : TJoueur &joueur

void ResultatsJoueur(TJoueur joueur, int &nbsucces, int &nbechec, int & nbessais);
// Nom : ResultatsJoueur
// Rôle : indique les résultats du joueur passé en paramètre
//        le nombre de parties gagnées, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations à l'écran
// Paramètres d'entrée: TJoueur joueur
// Paramètres de sortie: int &nbsucces, int &nbechec, int & nbessais

string Nom(TJoueur joueur);

// Nom :Nom
// Rôle : retourne le nom du joueur
// Paramètres d'entrée: le joueur dont on veut le nom
// Valeur de retour : nom du joueur
