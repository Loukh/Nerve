#include "header.h"


void initPerso(perso *p)
{
    TTF_Init();
    TTF_Font *police=NULL;
    police=TTF_OpenFont("Urusans.ttf",40);
    SDL_Color couleur= {255,255,255};

    p->sprite=IMG_Load("sprite sheet.png");

    p->posPerso.x=250;
    p->posPerso.y=290;

    p->posSprite.w=50;
    p->posSprite.h=40;
    p->posSprite.y=0;
    p->posSprite.x=0;

    p->vies=IMG_Load("hearts.jpg");
    p->posVie1.x=0;
    p->posVie1.y=0;

    p->posVie2.w=96;
    p->posVie2.h=26;
    p->posVie2.y=0;
    p->posVie2.x=0;

    p->posScore.x=0;
    p->posScore.y=30;


    p->score=0;
    char s[20];
    sprintf(s,"Score: %d",p->score);
    p->scoretxt=TTF_RenderText_Blended(police,s,couleur);
    p->vie=3;
    p->direction=2;


}

void afficherPerso(perso *p, SDL_Surface * screen)
{
    TTF_Init();
    TTF_Font *police=NULL;
    police=TTF_OpenFont("Urusans.ttf",40);
    SDL_Color couleur= {255,255,255};
    char s[20];
    sprintf(s,"Score: %d",p->score);
    SDL_FreeSurface(p->scoretxt);
    p->scoretxt=TTF_RenderText_Blended(police,s,couleur);


    SDL_BlitSurface(p->sprite,&p->posSprite,screen,&p->posPerso);
    SDL_BlitSurface(p->vies,&p->posVie2,screen,&p->posVie1);
    SDL_BlitSurface(p->scoretxt,NULL,screen,&p->posScore);

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
    else if(p->direction==5)
        p->posSprite.y=80;

    if(p->posSprite.x>=350)
        p->posSprite.x=0;

    else p->posSprite.x+=50*frame;




}
void saut (perso* p)
{
    p->posPerso.y--;
}

