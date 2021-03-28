#include "header.h"

int checkInt(float f)
{
    if((int)f==f)
        return 1;
    else return 0;

}

enigme generer()
{

    enigme e;

    float s1,s2;
    srand(time(NULL));
    while(checkInt(s2)==0&&s2!=0)
    {
        e.a=rand() % 10+1;
        e.b=rand() % 10+1;
        e.c=rand() % 10+1;
        s1=e.c-e.b;
        s2=s1/e.a;
    }
    e.x=s2;
    e.a2=e.a;
    e.b2=e.b;
    e.c2=e.c;
    while(e.a==e.b || e.a==e.c || e.b==e.c)
    {
        e.a=rand() % 10+1;
        e.b=rand() % 10+1;
        e.c=rand() % 10+1;
    }

    do
    {
        e.n1=rand() % 3+1;
        e.n2=rand() % 3+1;
        e.n3=rand() % 3+1;
    }
    while((e.n1==e.n2)||(e.n1==e.n3)||(e.n2==e.n3));


    return e;

}

void afficherEnigme(enigme e, SDL_Surface * screen)
{
    TTF_Init();
    TTF_Font *police=NULL;
    police=TTF_OpenFont("Urusans.ttf",65);
    SDL_Color couleur= {0,0,0};
    int i;
    char equation[20];
    char a[20];
    char b[20];
    char c[20];
    SDL_Rect pE,pA;
    pE.x=0;
    pE.y=0;
    SDL_Surface *ee;
    SDL_Surface *aa;




    sprintf(equation,"%dx + %d = %d",e.a2,e.b2,e.c2);

    ee=TTF_RenderText_Blended(police,equation,couleur);
    SDL_BlitSurface(ee,NULL,screen,&pE);
    printf("%dx + %d = %d\n\n",e.a2,e.b2,e.c2);

    for(i=1; i<4; i++)
    {
        switch(i)
        {
        case 1:
            strcpy(a,"A) ");
            pA.x=0;
            pA.y=60;
            break;
        case 2:
            strcpy(a,"B) ");
            pA.x=0;
            pA.y=120;
            break;
        case 3:
            strcpy(a,"C) ");
            pA.x=0;
            pA.y=180;
            break;
        }

        if(i==e.n1)
            sprintf(b,"%d",e.a);
        else if(i==e.n2)
            sprintf(b,"%d",e.b);
        else if(i==e.n3)
            sprintf(b,"%d",e.x);
        strcat(a,b);
        aa=TTF_RenderText_Blended(police,a,couleur);
        SDL_BlitSurface(aa,NULL,screen,&pA);
    }

}

