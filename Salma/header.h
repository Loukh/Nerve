#ifndef HEADER_H_
#define HEADER_H_
#include <stdio.h>
#include <stdlib.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>
#include<time.h>

typedef struct 
{
int a;
int b;
int c;
int x;
int a2;
int b2;
int c2;
int n1;
int n2;
int n3;
int n;
int n4;

}enigme;



enigme generer();
void afficherEnigme(enigme e, SDL_Surface * screen);
int checkInt(float f);


#endif
