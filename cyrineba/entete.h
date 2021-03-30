#ifndef ENTETE_H_INCLUDED
#define ENTETE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<SDL/SDL.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_mixer.h>

typedef struct 
{
  SDL_Surface *map;
  SDL_Surface *joueur;
  SDL_Rect posmap;
  SDL_Rect posjoueur ;
}minimap;
typedef enum
{
left ,up ,right,down
}direction;
typedef enum
{
true,false
}bool;

//declaration des fonction 
void initmap(minimap *m);
SDL_Rect MAJMinimap(SDL_Rect posJoueur , int redimensionnement);
void afficherminimap(minimap m,SDL_Surface *screen ) ;
void Liberer(minimap * m );
void affichertemps(int temps ,SDL_Surface *screen);
bool collision(SDL_Rect* rect1, SDL_Rect* rect2);
bool collisionmap (direction d, int collX, int collY);















#endif 
