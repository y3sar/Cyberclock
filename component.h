#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct {
	SDL_Renderer* source_renderer;
	SDL_Point* center_pos;
	SDL_Texture* texture;
	SDL_Rect* dst_rect;
	int angle;
} Component;


void init_component(Component* component, char* image_file, SDL_Renderer* source_renderer, SDL_Rect* dst_rect, int angle, SDL_Point* center_pos);
void rotate_component(Component* component, int new_angle); // assigns new angle to the component
void move_component(Component* component, int new_x, int new_y);// assigns new cordinate value to the component
void scale_component(Component* component, int new_w, int new_h); //assigns new height and width to the component
int render_component(Component* component);


#endif
