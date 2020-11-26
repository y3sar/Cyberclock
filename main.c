#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "component.h" 

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300

int init_system();

SDL_Renderer* main_renderer = NULL;
SDL_Window* main_window = NULL;




Component ClockBackground;

Component ClockHand;;


int main(){
	init_system();
	init_component(&ClockBackground, "assets/clock.png", main_renderer, NULL, 0, NULL);

	int quit = 0;
	SDL_Event e;
	while (!quit){

		while ( SDL_PollEvent(&e) != 0){
			if (e.type == SDL_QUIT){
				quit = 1;
			}
		}

		SDL_RenderClear(main_renderer);
		render_component(&ClockBackground);
		SDL_RenderPresent(main_renderer);
		
	}
}





int init_system(void){
	int success = 1;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("error initializing SDL2\n");
		success = 0;
	}

	// Creates the window and defines height and width
	main_window = SDL_CreateWindow("CyberClock", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
			                                         SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	// Creates the renderer on the window
	main_renderer = SDL_CreateRenderer(main_window, -1, SDL_RENDERER_ACCELERATED);

	// This is the color renderer will be in when Cleared
	SDL_SetRenderDrawColor( main_renderer, 0xFF, 0xFF, 0xFF, 0xFF );

	IMG_Init(IMG_INIT_PNG);

	if (main_window == NULL){
		printf("window could not be created! SDL_Error: %s\n", SDL_GetError());
		success = 0;
	}

	if (main_renderer == NULL){
		printf("renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		success = 0;
	}


	return success;

}
