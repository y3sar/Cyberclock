#ifndef COMPONENTS_H
#define COMPONENTS_H


typedef struct {
	SDL_Renderer* source_renderer;
	SDL_Point* center_pos;
	SDL_Texture* texture;
	SDL_Rect* dst_rect;
	int x 
	int y 
	int w 
	int h 
	int angle;
} Component;

int init_component(const *char image_file, int x, int y, int w, int h, int angle, *SDL_Point, center_pos);
int rotate_component(*Component component, int new_angle); // assigns new angle to the component
int move_component(*Component component, int new_x, int new_y);// assigns new cordinate value to the component
int scale_component(*Component component, int new_w, int new_h); //assigns new height and width to the component

#endif
