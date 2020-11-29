#ifndef COMPONENTS_H
#define COMPONENTS_H

typedef struct {
	SDL_Renderer* source_renderer;
	SDL_Point* center_pos;
	SDL_Texture* texture;
	SDL_Rect* dst_rect;
	int angle;
} Component;

typedef struct {
	SDL_Renderer* source_renderer;
	SDL_Texture* texture;
	SDL_Rect* dst_rect;
	TTF_Font* font_style;
	SDL_Color text_color;
} TextComponent;


void init_component(Component* component, char* image_file, SDL_Renderer* source_renderer, SDL_Rect* dst_rect, int angle, SDL_Point* center_pos);

void init_text_component(TextComponent* text_component, char* text, TTF_Font* font_style, SDL_Color text_color, SDL_Renderer* source_renderer, SDL_Rect* dst_rect);
void rotate_component(Component* component, int new_angle); // assigns new angle to the component
void move_component(Component* component, int new_x, int new_y);// assigns new cordinate value to the component
void scale_component(Component* component, int new_w, int new_h); //assigns new height and width to the component

int render_component(Component* component);
int render_text_component(TextComponent* text_component);

void change_text(TextComponent* text_component, char* text);




#endif
