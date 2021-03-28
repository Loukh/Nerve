#include "header.h"


int main()
{
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
    SDL_Event event;
    TTF_Init();
    TTF_Font *police=NULL;
    police=TTF_OpenFont("Urusans.ttf",65);
    SDL_Color couleur= {0,0,0};

    SDL_Surface *screen=NULL;
    SDL_Surface *bg=NULL;
    SDL_Surface *result=NULL;
    bg=IMG_Load("b.png");
    screen=SDL_SetVideoMode(600,385,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    SDL_Rect pos;
    SDL_Rect posResult;
    pos.x=0;
    pos.y=0;
    posResult.x=250;
    posResult.y=120;

    int continuer=1;
    int reponse=-1;
    enigme e=generer();

    while (continuer)
    {
        SDL_WaitEvent(&event);
        SDL_BlitSurface(bg,NULL,screen,&pos);

        afficherEnigme(e,screen);

        switch(event.type)
        {
        case SDL_QUIT :
            continuer=0;
            break;
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                continuer=0;
                break;
            case SDLK_a:
                reponse=1;
                break;
            case SDLK_b:
                reponse=2;
                break;
            case SDLK_c:
                reponse=3;
                break;
            }
            break;
        }
        if(reponse==e.n3)
        {
            SDL_FreeSurface(result);
            result=TTF_RenderText_Blended(police,"Correct",couleur);
            SDL_BlitSurface(result,NULL,screen,&posResult);
        }
        else if(reponse!=e.n3&&reponse!=-1)
        {
            SDL_FreeSurface(result);
            result=TTF_RenderText_Blended(police,"Incorrect",couleur);
            SDL_BlitSurface(result,NULL,screen,&posResult);
        }

        SDL_Flip(screen);
    }

}

