# This is a Clock app written in C.


# TODO
- [ ] Make code more modular with header files and stuff
- [ ] Make the clockhand rotate along the middle circle


# Structure of the project

Every clock component (clockhand, clock body, time label) all of it will be a component structure
Maybe the time label structure will have a seperate struct def but clockhand and clock body can share the same structure

Component structure elements

SDL_Texture* // to store texture of the image
SDL_Rect* pos // to store position of the texture
int x,y,w,h // to easily manipulate size and position


Functions for the components

init function
rotate function
move function
scale function
render function

