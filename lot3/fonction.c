#include "entete.h"

void initmap(minimap *m )
{

(*m).map=IMG_Load("mini.jpg");
(*m).joueur=IMG_Load("point.png");
(*m).posmap.x=472;
(*m).posmap.y=0;
(*m).posjoueur.x=510;
(*m).posjoueur.y=65;
(*m).direction=0;

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

int collisionmap (SDL_Surface *masque,SDL_Rect posjoueur,SDL_Surface *joueur,int d)
{
    SDL_Color col;
    
   if(d==1)//imin
  {
    col=GetPixel(masque,posjoueur.x+joueur->w,posjoueur.y+(joueur->h/2));
  }
else  if(d==0)//issarr
  {
    col=GetPixel(masque,posjoueur.x,posjoueur.y+(joueur->h/2));
  }

    if(col.r == 0 && col.g == 0 && col.b ==0) 
return 1;
else return 0;

}



