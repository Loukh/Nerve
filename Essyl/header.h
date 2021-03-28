#ifndef HEADER_H
#define HEADER_H

#include<stdio.h>
#include<stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include<SDL/SDL_mixer.h>

struct Background
{
    SDL_Surface *backgroundImg;
    Mix_Music *backgroundMus;
    SDL_Rect camera_pos;
};
typedef struct Background Background;
//Struct louay
typedef struct
{
    SDL_Surface *sprite;
    SDL_Rect posPerso;
    SDL_Rect posSprite;

    int direction;
    int score;
    int vie;


} perso;


//Declaration Des Fonctions
int charger_Background(Background *B);
int charger_Backmusic(Background *B);
void initBackground(Background *B);
void affBackground(Background B, SDL_Surface *screen);
void freeBackground(Background *B);
void scrolling(Background *B,int direction);
//Fonctions Louay
void initPerso(perso *p);
void afficherPerso(perso p, SDL_Surface * screen);
void deplacerPerso (perso *p);
void saut (perso* p) ;
void clips(SDL_Rect* c);
void animerPerso (perso* p,int frame);

#endif

