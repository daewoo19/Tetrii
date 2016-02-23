#ifndef _Utils_H
#define _Utils_H

#include <string>
#include "SDL/SDL.h"

SDL_Surface *load_image( std::string filename );
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL );

#endif

