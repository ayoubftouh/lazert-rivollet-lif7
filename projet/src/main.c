#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"
#include "affiche.h"
#include "ordinateur.h"
#include "menuprincipal.h"
#include "jeu.h"

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
    @brief Fonction du jeu

    @return int
*/
int main ()
{
    int rejouer;
    rejouer=1;
    while(rejouer==1)
    {
        rejouer=menuPrincipal();
        rejouer=Jouer();
    }
    return 0;
}
