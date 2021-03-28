#include"header.h"


//Fonctions Louay


void initPerso(perso *p)
{
    p->sprite=SDL_DisplayFormat(IMG_Load("sprite.png"));

    p->posPerso.x=264;
    p->posPerso.y=215;

    p->posSprite.w=50;
    p->posSprite.h=40;
    p->posSprite.y=0;
    p->posSprite.x=0;

    p->score=0;
    p->vie=15;
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
//Mes Fonctions 
void initEnnemi(Ennemi *E)
{
    (*E).sprite=SDL_DisplayFormat(IMG_Load("sprite.png"));
    (*E).posScreen.x=264;
    (*E).posScreen.y=215;
    (*E).posSprite.x=0;
    (*E).posSprite.y=0;
    (*E).posSprite.w=50;
    (*E).posSprite.h=40;
    (*E).direction=0;

}

void afficherEnnemni(Ennemi E,SDL_Surface *screen)
{
    SDL_BlitSurface(E.sprite,&E.posSprite,screen,&E.posScreen);

}



void animerEnnemi(Ennemi *E,int frame)
{
    if ((*E).direction==0)
     (*E).posSprite.y=40;
     else if ((*E).direction==1)
     (*E).posSprite.y=160;
 
     
    if ((*E).posSprite.x>=350)
       (*E).posSprite.x=0;
    else
        (*E).posSprite.x+=50*frame;

}

Ennemi deplacerEnnemi(Ennemi E)
{
    int posMax,posMin;
    posMax=318;
    posMin=263;
    if (E.posScreen.x> posMax)
        E.direction=1;
    if (E.posScreen.x< posMin)
        E.direction=0;
    if (E.direction==0)
        E.posScreen.x++;
    else
        E.posScreen.x--;
        
      
        
    return (E);
}
int collisionBB(perso p,Ennemi E)

{
    int collision;
    if(((p.posPerso.x+p.posPerso.w) < (E.posScreen.x))||((p.posPerso.x) < (E.posScreen.x+E.posScreen.w))||((p.posPerso.y+p.posPerso.h) < (E.posScreen.y))||((p.posPerso.y) < (E.posScreen.y+E.posScreen.h)))
        collision=0;
    else
        collision=1;
    return collision;
}








