#include "entete.h"



int  main ()
{
    int continuer =1,temps=0;
    int collX,collY;
    

     
    SDL_Event event;
    minimap m;
    SDL_Surface *screen ;
    SDL_Surface *perso;
    SDL_Surface *img ;
    SDL_Surface *masqueb;
    img=IMG_Load("b.jpg"); 
    masqueb=IMG_Load("masque.bmp");
    perso=IMG_Load("point.png");
    SDL_Rect posscreen ;
    SDL_Rect posperso;
    posperso.x=275;
    posperso.y=460;
    posscreen.x=0;
    posscreen.y=0;


    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER);
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_TIMER)!=0)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }

    screen=SDL_SetVideoMode(640,600,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
    if(screen==NULL)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    int frame=0;
    const int FPS=20;

    Uint32 start;
    initmap (&m);
    SDL_BlitSurface(img,NULL,screen,&posscreen);
SDL_EnableKeyRepeat(1,1);
int test=0;

    while (continuer)
    {
        SDL_BlitSurface(masqueb,NULL,screen,&posscreen);
        SDL_BlitSurface(img,NULL,screen,&posscreen);
        SDL_BlitSurface(perso,NULL,screen,&posperso);
        affichertemps(temps,screen);
        start=SDL_GetTicks();
        afficherminimap(m,screen) ;

         test=collisionmap (masqueb,posperso,perso,m.direction);
printf("test %d\n",test);

        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {
            case SDL_QUIT:
                continuer=0;
                break;
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    continuer=0;
                    break;
                case SDLK_RIGHT:
m.direction=1;
if(collisionmap (masqueb,posperso,perso,m.direction)==0)
{
		    
                    posperso.x+=10;
                    if(m.posjoueur.x<=m.posmap.x+100)

                        m.posjoueur.x++;
}
                    break;
                case SDLK_LEFT:
m.direction=0;
if(collisionmap (masqueb,posperso,perso,m.direction)==0)
{

                    posperso.x-=10;
                    if(m.posjoueur.x>=m.posmap.x)
                        m.posjoueur.x--;
}
                    break;
                }
                break;
            }
        }

  
    frame++;
    if(frame==20)
    {
        frame=0;
        temps++;
    }
    if(1000/FPS>SDL_GetTicks()-start)
        SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    SDL_Flip(screen);
}//finwhile
Liberer(&m);
return 0;
}

