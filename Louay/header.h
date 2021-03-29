#ifndef HEADER_H_
#define HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>


//structute de personnage

typedef struct 
{
SDL_Surface *sprite;
SDL_Surface *vies;
SDL_Surface *scoretxt;
SDL_Rect posPerso;
SDL_Rect posSprite;
SDL_Rect posVie1;
SDL_Rect posVie2;
SDL_Rect posScore;

int direction;
int score;
int vie;


}perso;

//void init (personne * p, int numperso);
void initPerso(perso *p);
void afficherPerso(perso *p, SDL_Surface * screen);
void deplacerPerso (perso *p);
void saut (perso* p) ;
void clips(SDL_Rect* c);
void animerPerso (perso* p,int frame);


#endif
