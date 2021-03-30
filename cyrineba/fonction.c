#include "entete.h"

void initmap(minimap *m )
{

(*m).map=IMG_Load("mini.jpg");
(*m).joueur=IMG_Load("point.png");
(*m).posmap.x=472;
(*m).posmap.y=0;
(*m).posjoueur.x=536;
(*m).posjoueur.y=65;

}


void afficherminimap(minimap m,SDL_Surface *screen ) 
{
 SDL_BlitSurface (m.map,NULL,screen,&(m.posmap));

 SDL_BlitSurface (m.joueur,NULL,screen,&(m.posjoueur));
 

}

void Liberer(minimap * m )
{
free(m->joueur);
free(m->map);
}



void affichertemps(int temps ,SDL_Surface *screen)
{

    TTF_Init();
    TTF_Font *police=NULL;
    police=TTF_OpenFont("Urusans.ttf",40);
    SDL_Color couleur= {0,0,0};
    SDL_Rect postemps;
    postemps.x=0;
    postemps.y=0;
    char s[20];
    sprintf(s,"Temps: %d",temps);
    SDL_Surface *txt;
    txt=TTF_RenderText_Blended(police,s,couleur);
    SDL_BlitSurface(txt,NULL,screen,&postemps);
     

}


SDL_Color GetPixel (SDL_Surface* pSurface , int x , int y)
{
    SDL_Color color;
    Uint32 col = 0 ;
    if (x >= 0 && y >= 0)
    {
        //determine position
        char* pPosition = ( char* ) pSurface->pixels ;

        //offset by y
        pPosition += ( pSurface->pitch * y ) ;

        //offset by x
        pPosition += ( pSurface->format->BytesPerPixel * x ) ;

        //copy pixel data
        memcpy ( &col , pPosition , pSurface->format->BytesPerPixel ) ;

        //convert color
    }
    SDL_GetRGB ( col , pSurface->format , &color.r , &color.g , &color.b ) ;
    return ( color ) ;
}
bool collision(SDL_Rect* rect1, SDL_Rect* rect2)
{
    if (rect1->y >= rect2->y + rect2->h)
        return false;
    if (rect1->x >= rect2->x + rect2->w)
        return false;
    if (rect1->y + rect1->h <= rect2->y)
        return false;
    if (rect1->x + rect1->w <= rect2->x)
        return false;
    return true;
}
bool collisionmap (direction d, int collX, int collY)
{
    SDL_Color couleur;
    SDL_Surface *masque;
   masque=IMG_Load("masque.bmp");
   
    if (d == up)
    {
        couleur = GetPixel(masque, collX + 35, collY - 49);
    }
    else if (d == down)
    {
        couleur = GetPixel(masque, collX + 35, collY + 59);
    }
    else if (d == right)
    {
        couleur = GetPixel(masque, collX + 40, collY + 54);
    }
    else if (d == left)
    {
        couleur = GetPixel(masque, collX - 30, collY + 54);
    }
    return ((couleur.r == 255 && couleur.g == 255 && couleur.b == 255) );

}
/*
int collisionPP(perso p,SDL_Surface *masque)
{
   int collision;
   int pos[9];

   SDL_Color noir= {0,0,0};
   SDL_Surface *masque;
   masque=IMG_Load("masque.bmp");
   SDL_Rect posperso;
    p.posperso.x=536;
    p.posperso.y=65;
    //p.posperso.h;
    //p.posperso.w;
    p1.x=p->posperso.x;
    p1.y=p->posperso.y;
    p2.x=(p->posperso.x+p->posperso.w)/2;
    p2.y=p->posperso.y;
    p3.x=(p->posperso.x+p->posperso.w);
    p3.y=p->posperso.y;
    p4.x=p->posperso.x;
    p4.y=(p->posperso.y+p->posperso.h)/2;
    p5.x=p->posperso.x;
    p5.y=(p->posperso.y+p->posperso.h);
    p6.x=(p->posperso.x+p->posperso.w)/2;
    p6.y=(p->posperso.y+p->posperso.h);
    p7.x=(p->posperso.x+p->posperso.w);
    p7.y=(p->posperso.y+p->posperso.h);
    p8.x=(p->posperso.x+p->posperso.w);
    p8.y=(p->posperso.y+p->posperso.h)/2;

}*/



