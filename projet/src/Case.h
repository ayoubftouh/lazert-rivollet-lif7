#ifndef _CASE
#define _CASE

#include "parametres.h"

#include <stdlib.h>
#include <stdio.h>

/**
    @struct Case
    @brief Structure pour les cases du plateau de jeu
*/
typedef struct
{

	int libre; /*!< savoir si la case est libre ou occupée par un joueur */
	int joueur; /*!< numéro du joueur qui possède le pion */
	int posX; /*!< coordonnée x du pion sur le support */
	int posY; /*!< coordonnée y du pion sur le support */
}Case;

/**
    @brief alloue de la memoire dans le tas et retourne l'adresse

    @param void

    @return pointeur sur case
*/
Case* caseInit(void);


/**
    @brief Donner une position x,y a une case

    @param [IN,OUT] c : pointeur sur la case à modifier
    @param [IN] x : position horizontale
    @param [IN] y : position verticale

    @return void
*/
void caseSetPos(Case* c, int x, int y);


/**
    @brief Savoir si une case est libre

    @param [IN] case : pointeur sur case

    @return 1 si la case est libre et 0 sinon
*/
int caseGetLibre(const Case* c);


/**
    @brief Rendre libre ou non une case

    @param [IN,OUT] c : pointeur sur la case a modifier
    @param [IN] val : booléen : libre ou non

    @return void
*/
void caseSetLibre(Case* c, int val);


/**
    @brief Retourne le joueur qui a un pion sur la case

    @param [IN] c : pointeur sur case

    @return numero du joueur
*/
int caseGetJoueur(const Case* c);


/**
    @brief Modifier le joueur qui a un pion sur la case

    @param [IN,OUT] c : pointeur sur case
    @param [IN] j : numéro du joueur

    @return void
*/
void caseSetJoueur(Case* c, int j);


/**
    @brief Retourne la coordonnee X

    @param [IN] c : pointeur sur case

    @return coordonnee entiere
*/
int caseGetX(const Case* c);


/**
    @brief Retourne la coordonnee Y

    @param [IN] c : pointeur sur case

    @return coordonnee entiere
*/
int caseGetY(const Case* c);


/**
    @brief Comparer les coordonnées en paramètres avec celles de la case

    @param [IN] c : Pointeur sur Case
    @param [IN] sx : coordonnée horizontale
    @param [IN] sy : coordonnée verticale

    @return int (booléen)
*/
int caseTestCoordonnees(Case* c,int sx,int sy);


/**
    @brief Détruire la case pour libérer la mémoire.

    @param [IN] c : Pointeur sur la case à détruire

    @return void
*/
void caseTestament(Case* c);


/**
    @brief Test de régression pour vérifier le module Case

    @param void

    @return void
*/
void caseTestRegression(void);

#endif
