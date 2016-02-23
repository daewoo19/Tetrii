/*
Source code for these functions are take from lazyfoo.net
Provides functions to help make using SDL easier.  
*/

#ifndef _Utils_H
#define _Utils_H

#include <string>
#include "SDL/SDL.h"


// Loads an image file and returns an optimized version of it.
SDL_Surface *load_image( std::string filename );

// Applies and draws the surface on to another surface based on x,y offsets
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

#endif

