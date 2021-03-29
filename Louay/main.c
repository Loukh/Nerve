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
    SDL_Surface *img=NULL;
    img = IMG_Load("b.png");
    screen=SDL_SetVideoMode(600,385,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

    if(screen==NULL)
    {
        printf("error : %s \n",SDL_GetError());
        return 1;
    }
    SDL_Rect posImage;




    posImage.x=0;
    posImage.y=0;
    Uint32 c=SDL_MapRGB(screen->format,0x00,0x00,0x00);
    int gamerunning=1;

    int frame=0;
    int jumpC=0,j=0;
    int counter=0;
    int timee;
    int a;
    int b;
    float eljeya;
    int hold=0;
    const int FPS=40;




    Uint32 start;
    perso p;
    initPerso(&p);
    SDL_EnableKeyRepeat(1,1);

    while(gamerunning)
    {
        if(counter==20)
        {
            counter=0;
            p.score++;
        }
 SDL_BlitSurface(img,NULL,screen,&posImage);
        start=SDL_GetTicks();
        b=SDL_GetTicks();
        timee=b-a;
        afficherPerso(&p,screen);
        animerPerso(&p,frame);
        if(jumpC==1)
        {
            j++;
            if(j==17)
            {
                j=0;
                jumpC=0;
            }
        }

        while(SDL_PollEvent(&event))
        {

            switch(event.type)
            {

            case SDL_QUIT:
                gamerunning=0;
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
                    jumpC=1;
                    hold=p.direction;
                    p.direction=5;

                    break;
		case SDLK_m:
if(p.posVie2.w<=96 && p.posVie2.w>0)
                    p.posVie2.w-=32;
                    break;
               case SDLK_l:
                    if(p.posVie2.w<=96 && p.posVie2.w>0)
                    p.posVie2.w+=32;
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
            }
        }
        if(j<=8)
            p.posPerso.y= p.posPerso.y-(2*j);
        else if(j>8)
            p.posPerso.y= p.posPerso.y+(2*(j-8));
        if(16==j)
            p.direction=hold;


        SDL_Flip(screen);
        a=SDL_GetTicks();
        counter++;
        frame++;
        if(frame==6)
            frame=0;
        if(1000/FPS>SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
}

