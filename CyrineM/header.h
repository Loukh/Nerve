#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct
{
    SDL_Surface * sprite;
    SDL_Rect posScreen;
    SDL_Rect posSprite;
    int direction;//0 droite 1 gauche
} Ennemi;
//structute du personnage

typedef struct 
{
SDL_Surface *sprite;
SDL_Rect posPerso;
SDL_Rect posSprite;

int direction;
int score;
int vie;


}perso;

//Declaration des fonctions
void initEnnemi(Ennemi *E);
void afficherEnnemni(Ennemi E,SDL_Surface *screen);
void animerEnnemi(Ennemi *E,int frame);
Ennemi deplacerEnnemi(Ennemi E);
int collisionBB(perso p,Ennemi E);
//Declaration Fonctions louay
void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void deplacerPerso (perso *p);
void saut (perso* p) ;
void clips(SDL_Rect* c);
void animerPerso (perso* p,int frame);




#endif

