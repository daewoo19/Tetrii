#include "Options.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "_utils.h"

Options::Options(SDL_Surface *_screen) : _SCREEN(_screen)
{
	// Init Text
	TTF_Font *font;
	font = TTF_OpenFont( "ariblk.ttf", 36 );

	SDL_Color color;
	color.r = 200;
	color.g = 200;
	color.b = 200;

	txtOptions	= TTF_RenderText_Solid(font, "Credits", color);

	font = TTF_OpenFont( "ariblk.ttf", 24 );

	txtCredits1	= TTF_RenderText_Solid(font, "copyright - 2007", color);
	txtCredits2	= TTF_RenderText_Solid(font, "Victor Yap & David Wu", color);
	// Load Images
	background = load_image("images/background-01.png");
	selectCursor = load_image("images/point.png");

	// State Variables
	selectState = START;
}

Options::~Options()
{
	SDL_FreeSurface( background );
	SDL_FreeSurface( txtOptions );
	SDL_FreeSurface( selectCursor );
	SDL_FreeSurface( txtCredits1 );
	SDL_FreeSurface( txtCredits2 );
}

void Options::redraw()
{
	// Background
	apply_surface(0, 0, background, _SCREEN);

	// Text
	apply_surface(600, 30, txtOptions, _SCREEN);
	apply_surface(60, 330, txtCredits1, _SCREEN);
	apply_surface(60, 300, txtCredits2, _SCREEN);

	SDL_Flip( _SCREEN );
}
