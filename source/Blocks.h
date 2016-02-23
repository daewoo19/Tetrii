/*This class contains the surfaces each of the various pieces*/

#ifndef Blocks_H
#define Blocks_H

#include "SDL/SDL.h"

class Blocks
{
public:
	Blocks();
	~Blocks();
public:
	// Load the graphics for the blocks.
	void Init();
	
	// Various surfaces for different block types
	SDL_Surface *I;
	SDL_Surface *O;
	SDL_Surface *L;
	SDL_Surface *J;
	SDL_Surface *S;
	SDL_Surface *Z;
	SDL_Surface *T;
};

#endif

