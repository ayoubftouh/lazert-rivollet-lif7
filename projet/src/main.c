#include <stdio.h>
#include <stdlib.h>

#include "parametres.h"
#include "Plateau.h"

#include <SDL/SDL.h>
#include <SDL_image.h>


int main ()
{
    Plateau jeu;

    /* on charge le plateau de jeu */
    lirePlateau(&jeu,"../data/Plateau1.txt");

    /* on charge les images pour les pions des 2 joueurs */
    pion1 = IMG_Load(PION_JOUEUR_1);
    pion2 = IMG_Load(PION_JOUEUR_2);

    /* erreurs de chargement ? */
    if (!pion1)
    {
        printf("Erreur de chargement du pion du joueur 1 : %s\n", SDL_GetError());
        return 1;
    }
    if (!pion2)
    {
        printf("Erreur de chargement du pion du joueur 2 : %s\n", SDL_GetError());
        return 1;
    }

    /* on charge l'image d'un case (normale et jouable) */
    case_vide = IMG_Load(CASE_VIDE);
    case_jouable = IMG_Load(CASE_JOUABLE);
    case_jouable_3 = IMG_Load(CASE_JOUABLE_3);
    case_jouable_4 = IMG_Load(CASE_JOUABLE_4);

    /* erreurs de chargement ? */
    if (!case_vide)
    {
        printf("Erreur de chargement de la case vide: %s\n", SDL_GetError());
        return 1;
    }
    if (!case_jouable)
    {
        printf("Erreur de chargement de la case jouable: %s\n", SDL_GetError());
        return 1;
    }

    /* on charge l'écran d'affichage */
    screen = SDL_SetVideoMode(1100, 800, 16, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (!screen)
    {
        printf("Erreur de définition de l'écran video : %s\n", SDL_GetError());
        return 1;
    }


    /* on vide l'écran */
    SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
    /* on initialise SDL video */
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "Erreur d'initialisation SDL: %s\n", SDL_GetError() );
        return 1;
    }

    /* make sure SDL cleans up before exit */
    atexit(SDL_Quit);


    /* variables pour contenir les coordonnées de la souris */
    int sourisx;
    int sourisy;

    /* variable pourr savoir quel joueur doit jouer */
    int qui_joue = 1; /* le joueur 1 commence */

    Case* caseCliquee = 0;
    Case* caseTemp;

    /* boucle principale du programme */
    int i = 0;
    int done = 0;
    while (done==0)
    {
        SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));

        /* afficher le terrain de jeu */
        affichePlateau(&jeu);
        affichePiece(&jeu);

        /* détection des événements */
        SDL_Event event;

        /* position de la souris sur l'écran */
        sourisx = event.motion.x;
        sourisy = event.motion.y;

        while (SDL_PollEvent(&event))
        {
            /* test des événements */
            switch (event.type)
            {
                /* fermer */
                case SDL_QUIT:
                    done = 1;
                    break;

                /* touche enfoncée */
                case SDL_KEYDOWN:
                    {
                        /* touche ECHAP */
                        if (event.key.keysym.sym == SDLK_ESCAPE)
                            done = 1;

                        if(event.key.keysym.sym == SDLK_RIGHT)
                            i += 5;

                        if(event.key.keysym.sym == SDLK_LEFT)
                            i -= 5;
                        break;
                    }
                /* clic de souris */
                case SDL_MOUSEBUTTONDOWN:
                    {
                        caseTemp=caseSurvollee(sourisx,sourisy,&jeu);
                        if((caseTemp!=0)&&((getJoueur(caseTemp))==qui_joue))
                        {
                            caseCliquee=caseTemp;
                            printf("Case cliquée : %d\n",(int) caseCliquee);
                        }
                    }
            } /* fin du test des événements */
        }

        float x;
        float y;
        /* si on a un pointeur de case cliquée non nul */
        if(caseCliquee!=0)
        {
            /* on affiche la case en surbrillance */
            x = UNITE_X*(getX(caseCliquee)+DECAL_X);
            y = UNITE_Y*(getY(caseCliquee)+DECAL_Y);
            dessineCase(x,y,1);

            casesAutour(&jeu,caseCliquee);
        }

        /*if(sourisDansCase(sourisx,sourisy,jeu.support[0])==1)
        {
            dessinepion1(-160+i,230+2*UNITE_Y);
            dessinepion1(197.5+i,267.5);
            dessinepion2(-160+i,230);
        }*/


        SDL_Flip(screen);

    } /* fin de la boucle principale */

    printf("Sortie du programme --- \n");
    return 0;
}

