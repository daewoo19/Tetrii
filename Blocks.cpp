#include "Blocks.h"
#include "SDL/SDL.h"
#include "_utils.h"

Blocks::Blocks()
{
}

void Blocks::Init()
{
	I = load_image("images/block-I.png");
	O = load_image("images/block-O.png");
	L = load_image("images/block-L.png");
	J = load_image("images/block-J.png");
	S = load_image("images/block-S.png");
	Z = load_image("images/block-Z.png");
	T = load_image("images/block-T.png");
}

Blocks::~Blocks()
{
	SDL_FreeSurface( I );
	SDL_FreeSurface( O );
	SDL_FreeSurface( L );
	SDL_FreeSurface( J );
	SDL_FreeSurface( S );
	SDL_FreeSurface( Z );
	SDL_FreeSurface( T );
}

