#include "header.h"
//Fonction louay

void initPerso(perso *p)
{
    p->sprite=SDL_DisplayFormat(IMG_Load("sprite.png"));

    p->posPerso.x=250;
    p->posPerso.y=290;

    p->posSprite.w=50;
    p->posSprite.h=40;
    p->posSprite.y=0;
    p->posSprite.x=0;

    p->score=0;
    p->vie=3;
    p->direction=2;


}

void afficherPerso(perso p, SDL_Surface * screen)
{


    SDL_BlitSurface(p.sprite,&p.posSprite,screen,&p.posPerso);
}

void deplacerPerso (perso *p)
{

    switch(p->direction)
    {
    case 3:
        p->posPerso.x++;
        break;
    case 0:
        p->posPerso.x--;
        break;
    }

}

void animerPerso (perso* p,int frame)
{
    if(p->direction==3)
        p->posSprite.y=40;
    else if(p->direction==2)
        p->posSprite.y=0;

    else if(p->direction==0)
        p->posSprite.y=160;
    else if(p->direction==1)
        p->posSprite.y=120;

    if(p->posSprite.x>=350)
        p->posSprite.x=0;
    else p->posSprite.x+=50*frame;




}
void saut (perso* p)
{
    int i;
    for(i=0; i<30; i++)
        p->posPerso.y--;
    for(i=0; i<30; i++)
        p->posPerso.y++;
}
//Fonctions Essyl

int charger_Background(Background *B)
{

    B->backgroundImg = IMG_Load("b.png");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
int charger_Backmusic(Background *B)
{
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);
    B->backgroundMus=Mix_LoadMUS("musique.mp3");
    if (B->backgroundImg == NULL)
    {
        printf("erreur: %s\n", SDL_GetError());
        return (-1);
    }
    return (0);
}
void initBackground(Background *B)
{
   
    /*B->camera_pos.w = SCREEN_W;
    B->camera_pos.h = SCREEN_H;*/
    B->camera_pos.x=0;
    B->camera_pos.y=0;
}

void affBackground(Background B, SDL_Surface *screen)
{
    /*if(B->camera_pos.x>B->backgroundImg->w-SCREEN_W)
    	B->camera_pos.x=0;
    if(B->camera_pos.x<0)
    	B->camera_pos.x=B->backgroundImg->w-SCREEN_W;*/

    SDL_BlitSurface(B.backgroundImg, NULL, screen, &B.camera_pos);
    Mix_PlayMusic(B.backgroundMus,-1);

}
void freeBackground(Background *B)
{
    SDL_FreeSurface(B->backgroundImg);
    Mix_FreeMusic(B->backgroundMus);
}
void scrolling(Background *B,int direction)
{

    switch (direction)
    {
    case 3:
        //if (SDLK_LEFT)
        B->camera_pos.x--;
        break;
    case 2:
        //if (SDLK_DOWN)
        B->camera_pos.y++;
        break;
    case 1:
        //if (SDLK_UP)
        B->camera_pos.y--;
        break;

    case 0:
        //if (SDLK_RIGHT)
       B->camera_pos.x++;
        break;




    }//Fin switch
}

