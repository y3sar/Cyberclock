#include <stdio.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include "component.h" 

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300

int init_system();
void tick();

SDL_Renderer* main_renderer = NULL;
SDL_Window* main_window = NULL;




Component ClockBackground;

Component ClockHand;



int main(){
	init_system();

	init_component(&ClockBackground, "assets/clock.png", main_renderer, NULL, 0, NULL);

	SDL_Rect clockhand_pos;

	init_component(&ClockHand, "assets/clockhand.png", main_renderer, &clockhand_pos, 0, NULL);

	SDL_QueryTexture(ClockHand.texture, NULL, NULL, &clockhand_pos.w, &clockhand_pos.h);
	clockhand_pos.w /= 2;
	clockhand_pos.h /= 2;
	clockhand_pos.x = (SCREEN_WIDTH/2) - clockhand_pos.w/2;
	clockhand_pos.y = (SCREEN_HEIGHT/2) - clockhand_pos.h - 30;

	SDL_Point clockhand_pivotpoint = {(clockhand_pos.w/2), (clockhand_pos.h+35)};
	ClockHand.dst_rect = &clockhand_pos;
	ClockHand.center_pos = &clockhand_pivotpoint;

	int quit = 0;
	SDL_Event e;
	while (!quit){

		while ( SDL_PollEvent(&e) != 0){
			if (e.type == SDL_QUIT){
				quit = 1;
			}
		}

		tick(&ClockHand);

		SDL_RenderClear(main_renderer);
		render_component(&ClockBackground);
		render_component(&ClockHand);
		SDL_RenderPresent(main_renderer);
		
	}
}


void tick(Component* clockhand){

	struct tm* timenow;
	time_t rawtime;
	time(&rawtime);
	timenow = localtime(&rawtime);
	clockhand->angle = timenow->tm_sec * 6;

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
