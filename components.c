// This will define the components that are needed for the clock
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <stdlib.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "component.h"




void init_component(Component* component, char* image_file, SDL_Renderer* source_renderer, SDL_Rect* dst_rect, int angle, SDL_Point* center_pos){

	// loading texture from image file
	SDL_Surface* temp_surface = IMG_Load(image_file);
	component->texture = SDL_CreateTextureFromSurface(source_renderer, temp_surface);
	SDL_FreeSurface(temp_surface);

	// the center point for rotation of the component
	component->center_pos = center_pos;

	// the context renderer
	component->source_renderer = source_renderer;

	// assigning the destination Rect sturcture
	component->dst_rect = dst_rect;

	// assigning the rotation angle
	component->angle = angle;
}




void init_text_component(TextComponent* text_component, char* text, TTF_Font* font_style, SDL_Color text_color, SDL_Renderer* source_renderer, SDL_Rect* dst_rect){

	SDL_Surface* temp_surface = TTF_RenderText_Solid(font_style, text, text_color);
	text_component->texture = SDL_CreateTextureFromSurface(source_renderer, temp_surface);
	
	text_component->font_style = font_style;
	text_component->source_renderer = source_renderer;
	text_component->dst_rect = dst_rect;
	
}

// changes the texture of the TextComponent to change the text
void change_text(TextComponent* text_component, char* text){

	SDL_Surface* temp_surface = TTF_RenderText_Solid(text_component->font_style, text, text_component->text_color);
	text_component->texture = SDL_CreateTextureFromSurface(text_component->source_renderer, temp_surface);

}

// assigns new angle to the component
void rotate_component(Component* component, int new_angle){ 

	component->angle = new_angle;
	
}	


// assigns new cordinate values to the component
void move_component(Component* component, int new_x, int new_y){

	component->dst_rect->x = new_x;
	component->dst_rect->y = new_y;

}



// assigns new width and height to the component
void scale_component(Component* component, int new_w, int new_h){
	component->dst_rect->w = new_w;
	component->dst_rect->h = new_h;
}


int render_component(Component* component){
	int ret;
	if (!(ret = SDL_RenderCopyEx(component->source_renderer, component->texture, NULL, component->dst_rect, component->angle, component->center_pos, SDL_FLIP_NONE)))
		return ret;
	printf("Error rendering component SDL Error:%s\n", SDL_GetError());
	return ret;
}

int render_text_component(TextComponent* text_component){
	int ret = SDL_RenderCopy(text_component->source_renderer, text_component->texture, NULL, text_component->dst_rect);
	if (!ret)
		return ret;
	printf("Error rendering component SDL Error:%s\n", SDL_GetError());
	return ret;
}
