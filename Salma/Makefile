prog:functions.o main.o
	gcc functions.o main.o -o prog -lSDL -lSDL_image -lSDL_ttf
main.o:main.c
	gcc -c main.c -lSDL -lSDL_image
functions.o:functions.c
	gcc -c functions.c -g
