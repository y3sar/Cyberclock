GTK_FLAGS = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
SDL_FLAGS = `pkg-config --cflags sdl2` `pkg-config --libs sdl2`

clockapp.out: main.o components.o component.h
	cc components.o main.o -o clockapp $(SDL_FLAGS) -lSDL2_image -lSDL2 -lSDL2_ttf

main.o: main.c 
	cc -c main.c $(SDL_FLAGS) -lSDL2_image -lSDL2 -lSDL2_ttf 

components.o: components.c 
	cc -c components.c $(SDL_FLAGS) -lSDL2_image -lSDL2 -lSDL2_ttf 

