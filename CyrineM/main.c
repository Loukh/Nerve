#include"header.h"


int main ()
{
    Ennemi E;
    SDL_Event event;
    SDL_Surface *screen=NULL;
    SDL_Surface *Background=NULL;
    SDL_Rect posBack;
    posBack.x=0;
    posBack.y=0;
    int continuer=1;
    int collision;
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    screen=SDL_SetVideoMode(474,296,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    initEnnemi(&E);
    
    
Background=IMG_Load("mario.jpeg");

    int frame=0;
    const int FPS=20;

    Uint32 start;
    perso p;
    initPerso(&p);
    SDL_EnableKeyRepeat(1,1);
   
   
    //Boucle De Jeu
    while(continuer)
    {   SDL_BlitSurface(Background,NULL,screen,&posBack);

        start=SDL_GetTicks();
         start=SDL_GetTicks();


        afficherPerso(p,screen);
        animerPerso(&p,frame);
        afficherEnnemni(E,screen);
        animerEnnemi(&E,frame);
        E=deplacerEnnemi(E);
        collision=collisionBB(p,E);
        if (collision==1)
        {
        p.vie=p.vie-1;
        p.score--;
        }
        if((p.vie==0)||(p.score<0))
        continuer=0;
        
        
        while( SDL_PollEvent(&event))
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
                    p.direction=3;

                    deplacerPerso(&p);
                    break;
                case SDLK_LEFT:
                    p.direction=0;

                    deplacerPerso(&p);
                    break;
               
                }
                break;

            case SDL_KEYUP:
                switch(event.key.keysym.sym)
                {
                case SDLK_RIGHT:
                    p.direction=2;
                    break;
                case SDLK_LEFT:
                    p.direction=1;
                    break;
                }
                break;
         
            }//FIN SWITCH
        }//Fin pollevent while
        
        SDL_Flip(screen);
        frame++;
        if(frame==8)
            frame=0;
        if(1000/FPS>SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));

    }//fin while
    return 0 ;
}

