#include "entete.h"

const int SCREEN_WIDTH = 600;
const int SCREEN_HEIGHT = 355;
const int SCREEN_BPP = 32;


SDL_Surface *background = NULL, *goodL=NULL,*goodD=NULL,*noobL=NULL,*noobD=NULL;
SDL_Surface *screen = NULL;
enigme e;

int main( int argc, char* args[] )
{
	SDL_Event event;
    	int true=1,reponse =-1;
    TTF_Init();
    SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO);
    int continuer = 1;
    int x,y,result=24;
    screen = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    
   	
	/*RECT*/
	SDL_Rect noobr,goodr;
	
	noobr.x=0;
	noobr.y=0;
	
	goodr.x=0;
	goodr.y=0;
	
	background=IMG_Load("room.png");
	goodL=IMG_Load("trueL.png");
	noobL=IMG_Load("noobL.png");

	goodD=IMG_Load("trueD.png");
	noobD=IMG_Load("noobD.png");

    SDL_WM_SetCaption( "NERVE", NULL );
    

	genererEnigme(&e);
	
	printf("%s\n",e.question);
	printf("%s %s %s\n",e.r1,e.r2,e.r3);
	printf("%d\n",e.numRepJuste);
	
	
	
	while(true)
		{
			
			SDL_WaitEvent(&event);
			SDL_BlitSurface(background,NULL,screen,0);
			
					
			
			afficherEnigme(e,screen);
			SDL_Flip(screen);
		printf("heelooo : %d\n",reponse);
	
			/**/

			
        switch(event.type)
        {
        case SDL_KEYDOWN:
        {
            switch(event.key.keysym.sym)
            {
            case SDLK_a :
                reponse=1;
                break;

            case SDLK_b :
                reponse=2;
                break;

            case SDLK_c :
                reponse=3;
                break;
		
            }

        }
        break;
        
    }
	printf("\n");
	printf("user reponse  :%d",reponse);
	printf("\n");
    if(reponse==e.numRepJuste)
        result = 1;
	else
    result = 0;			
		
			/**/
			
			/*
			result=resolutionEnigme(&e);
			*/
			/*
			switch(result)
			{
			case 0 : SDL_BlitSurface(noob,NULL,screen,&res);
					SDL_Flip(screen);
					 break ;
			case 1 : SDL_BlitSurface(good,NULL,screen,&res);
					SDL_Flip(screen);
					 break ; 
			}
				*/
			if(result==0)
				{
				SDL_BlitSurface(noobL,NULL,screen,&noobr);
				SDL_Flip(screen);	
				}
				else if (result == 1)
				{
				SDL_BlitSurface(goodL,NULL,screen,&goodr);
				SDL_Flip(screen);	
				}
		}
	
	SDL_FreeSurface(background);
        TTF_Quit();
        SDL_Quit();
    return 0;

}


