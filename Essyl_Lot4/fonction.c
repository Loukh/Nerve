#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include "header.h"




void initBackground(Background *B)
{
  Mix_Music *music;
  B->PositionBg.x=0;
  B->PositionBg.y=0;

  B->positionperso.x=0;
  B->positionperso.y=150;

  B->camera.x=0;
  B->camera.y=0;
  B->camera.w = 1280;
  B->camera.h = 336;

 //image
  B->BgImg= IMG_Load("background.bmp");
  if (B->BgImg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  B->PersoImg=IMG_Load("perso.png");
  if (B->PersoImg == NULL)
  {
    printf("Unable to load bitmap: %s\n", SDL_GetError());
  }

  //son
  if(SDL_Init(SDL_INIT_AUDIO)==-1)
  {
    printf("SDL_Init: %s\n", SDL_GetError());
  }
  if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024)==-1)
  {
    printf("Mix_OpenAudio: %s\n", Mix_GetError());
  }
  music=Mix_LoadMUS("musique.mp3");
  Mix_PlayMusic(music, -1);
  Mix_AllocateChannels(10);
  Mix_VolumeMusic(MIX_MAX_VOLUME);

  }

void afficherBack (Background *B,SDL_Surface *screen)
{

  SDL_BlitSurface(B->BgImg,&(B->camera),screen,&(B->PositionBg));
  SDL_BlitSurface(B->PersoImg,NULL,screen,&(B->positionperso));

}

void freeBackground(Background *B)
{
	SDL_FreeSurface(B->BgImg);
}



void scrolling(Background *B, bool b[])
{
  const int speed=5;
  if (b[0]) //right
  {
    if(B->positionperso.x<640)
    {
      B->positionperso.x+= 8;
    }

    if(B->positionperso.x>=640)
    {
      B->camera.x += speed;
    }

    if(B->camera.x >=2555-1280)
    {
      B->camera.x = 0;
      B->positionperso.x=0;
    }
  }
  if(b[1]) //left
  {
    if(B->positionperso.x<=640)
    {
      B->camera.x -= speed;
    }

    if(B->camera.x  <= 0)
    {
      B->camera.x  = 0;
      B->positionperso.x-=8;
    }
  }
  if(b[2]) //up
  {
    B->positionperso.y-=8;
   
    if(B->positionperso.y<=0)
    {
      B->positionperso.y=0;
    }
  }
  if(b[3]) //down
  {
    B->positionperso.y+=8;
    if(B->positionperso.y>=336)
    {
      B->positionperso.y=150;
    }
  }
}
