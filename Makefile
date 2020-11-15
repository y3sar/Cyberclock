GTK_FLAGS = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`
SDL_FLAGS = `pkg-config --cflags sdl2` `pkg-config --libs sdl2`

clockapp.out: clock.o
	cc -o clockapp clock.o $(SDL_FLAGS) -lSDL2_image -lSDL2

clock.o: clock.c 
	cc -c clock.c $(GTK_FLAGS) -lSDL2_image -lSDL2


