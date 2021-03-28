prog : main.o fonctions.o
	gcc main.o fonctions.o -o prog -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -g
main.o: main.c
	gcc -c main.c -g
fonctions.o: fonctions.c
	gcc -c fonctions.c -g
