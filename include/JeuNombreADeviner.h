/*************************************************/
// Nom du projet: Jeu du nombre � deviner
// Nom du fichier: JeuNombreADeviner.h
// Version : 1.0
// Nom du programmeur: MP Pinaud
// Date de cr�ation : 25/01/2021
// R�le du fichier: Contient la d�claration du type pour repr�senter un joueur
// et les fonctions concernant le jeu
// Nom des composants utilises: string
// Historique du fichier:
/*************************************************/
#include <string>
using namespace std;

//Type: structure TJoueur
// R�le : repr�sente un joueur. D�finit les propri�t�s d'un joueur.

typedef struct {

string nom;  // nom du joueur
int nbPartiesJouees; // nombre de parties jou�es
int nbPartiesGagnees; //nombre de parties gagn�es
int nbTentatives; //nombre de tentatives
} TJoueur;

void InitJoueur (TJoueur &joueurAcreer, string un_nom);
// Nom :InitJoueur
// R�le : Cr�e un joueur. Initialise toutes les informations du joueur.
//        Le nombre de tentatives, de parties gagn�es et de parties jou�es seront � 0.
// Param�tres d'entr�e : string_un_nom
// Param�tres de sortie : TJoueur
// Param�tres d'entr�e/sortie : &joueurAcreer

int TirerNombreMystere();
// Nom :TirerNombreMystere
// R�le : Tire al�atoirement un nombre � deviner entre 0 et 10
// Valeur de retour : nombre � deviner

void JouerPartie (TJoueur &un_joueur, int nombreADeviner);
// Nom :JouerPartie
// R�le : Fait jouer une partie au joueur pass� en param�tre
//        A la fin, met � jour les informations du joueur
// Param�tres d'entr�e: &un_joueur
// Param�tres de sortie: TJoueur, int nombreADeviner

void MajResultatsJoueur(TJoueur &joueur, int nbEssais, bool gagne);
// Nom : MajResultatsJoueur
// R�le : met � jour les informations du joueur pass� en param�tre
// Param�tres d'entr�e: bool gagne, int nbEssais
// Param�tres d'entr�e/sortie : TJoueur &joueur

void ResultatsJoueur(TJoueur joueur, int &nbsucces, int &nbechec, int & nbessais);
// Nom : ResultatsJoueur
// R�le : indique les r�sultats du joueur pass� en param�tre
//        le nombre de parties gagn�es, le nombre de parties perdues, le nombre d'essais total
//        La fonction N'affiche PAS les informations � l'�cran
// Param�tres d'entr�e: TJoueur joueur
// Param�tres de sortie: int &nbsucces, int &nbechec, int & nbessais

string Nom(TJoueur joueur);

// Nom :Nom
// R�le : retourne le nom du joueur
// Param�tres d'entr�e: le joueur dont on veut le nom
// Valeur de retour : nom du joueur
