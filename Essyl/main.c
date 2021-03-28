#include "header.h"

int main()
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);

    if(SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO)!=0)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }

    SDL_Event event;

    SDL_Surface *screen=NULL;
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,4096);
    int a,b;

    screen=SDL_SetVideoMode(600,385,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    int gamerunning=1;
    Background B;
    initBackground(&B);
    int frame=0;
    const int FPS=60;

    Uint32 start;
    perso p;
    initPerso(&p);
    SDL_EnableKeyRepeat(1,1);

    while(gamerunning)
    {
        start=SDL_GetTicks();

        
        a=charger_Background(&B);
        b=charger_Backmusic(&B);
        affBackground(B, screen);
        afficherPerso(p,screen);
        animerPerso(&p,frame);
        scrolling(&B,p.direction);
        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {

            case SDL_QUIT:
                gamerunning=0;
                freeBackground(&B);
                break;
           
            case SDL_KEYDOWN:
                switch(event.key.keysym.sym)
                {
                case SDLK_ESCAPE:
                    gamerunning=0;
                    break;
                case SDLK_RIGHT:
                    p.direction=3;

                    deplacerPerso(&p);
                    break;
                case SDLK_LEFT:
                    p.direction=0;

                    deplacerPerso(&p);
                    break;
                case SDLK_UP:
                    p.direction=2;
                    break;
                case SDLK_DOWN:
                    p.direction=1;
                    break;
                    }//Fin switch key 
                }//Fin Switch
            }//Fin PollEvent
            SDL_Flip(screen);


            frame++;
            if(frame==8)
                frame=0;
            if(1000/FPS>SDL_GetTicks()-start)
                SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
        }//End gameloop
        SDL_FreeSurface(screen);
        SDL_FreeSurface(B.backgroundImg);
        Mix_FreeMusic(B.backgroundMus);
        SDL_Quit();

        return 0;
    }













