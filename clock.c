#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <SDL2/SDL_image.h>
#include <time.h>

#define SCREEN_WIDTH 300
#define SCREEN_HEIGHT 300

SDL_Window* main_window = NULL;
SDL_Surface* main_surface = NULL;
SDL_Surface* clock_surface = NULL;
SDL_Surface* clockhand_surface = NULL;

SDL_Renderer* main_renderer = NULL;
SDL_Texture* clock_texture = NULL;
SDL_Texture* clockhand_texture = NULL;

int init_clock(void);
int load_assets(void);
SDL_Texture* load_texture(char* filename);
void destroy_clock(void);


int main(){
	//While application is running
	
	init_clock();
	load_assets();

	int quit = 0;
	SDL_Event e;

	while( !quit )
	{
			//Handle events on queue
			while( SDL_PollEvent( &e ) != 0 )
			{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
							quit = 1;
					}
			}

			//Clear screen
			SDL_RenderClear( main_renderer );

			//Render texture to screen
			SDL_RenderCopy( main_renderer, clock_texture, NULL, NULL );
			SDL_RenderCopy( main_renderer, clockhand_texture, NULL, NULL );

			//Update screen
			SDL_RenderPresent(main_renderer);
	}
	destroy_clock();
}


int init_clock(void){
	int success = 1;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		printf("error initializing SDL\n");
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

	else
		main_surface = SDL_GetWindowSurface(main_window);

	return success;

}

int load_assets(void){
	int success = 1;
	clock_texture = load_texture("assets/clock.png");
	if (clock_texture == NULL){
		success = 0;
		printf("error loading clock texture SDL error: %s\n", SDL_GetError());
	}

	clockhand_texture = load_texture("assets/clockhand.png");

	if (clockhand_texture == NULL){
		success = 0;
		printf("error loading clockhand texture SDL error: %s\n", SDL_GetError());
	}

	return success;
}

void destroy_clock(void){
	SDL_FreeSurface(main_surface);
	main_surface = NULL;

	SDL_DestroyWindow(main_window);
	main_window = NULL;

	SDL_Quit();
}

SDL_Texture* load_texture(char* filename){
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(filename);

	// Creates texture from a surface
	newTexture = SDL_CreateTextureFromSurface(main_renderer, loadedSurface);

	// Destroys the temprorary surface
	SDL_FreeSurface(loadedSurface);

	return newTexture;
}
























