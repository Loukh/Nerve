#ifndef HEADER_H_
#define HEADER_H_
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
typedef struct enigme
{
	int ligne;
	char texte[20];
	char question[100];
	char r1[20];
	char r2[20];
	char r3[20];
	int numRepJuste;
	
}enigme;


int resolutionEnigme(enigme *e);
void genererEnigme(enigme *e);
void afficherEnigme(enigme e, SDL_Surface * screen);
#endif
