#include "Title.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"
#include "_utils.h"

Title::Title(SDL_Surface *_screen) : _SCREEN(_screen)
{
	// Init Text
	TTF_Font *font;
	font = TTF_OpenFont( "ariblk.ttf", 36 );

	SDL_Color color;
	color.r = 200;
	color.g = 200;
	color.b = 200;

	txtTetrii	= TTF_RenderText_Solid(font, "Tetrii", color);
	txtStart	= TTF_RenderText_Solid(font, "Start", color);
	txtOptions	= TTF_RenderText_Solid(font, "Credits", color);

	// Load Images
	background = load_image("images/background-01.png");
	selectCursor = load_image("images/point.png");

	// State Variables
	selectState = START;
}

Title::~Title()
{
	SDL_FreeSurface( background );
	SDL_FreeSurface( txtTetrii );
	SDL_FreeSurface( txtStart );
	SDL_FreeSurface( txtOptions );
	SDL_FreeSurface( selectCursor );
}

void Title::redraw()
{
	// Background
	apply_surface(0, 0, background, _SCREEN);

	// Text
	apply_surface(45, 90, txtTetrii, _SCREEN);
	apply_surface(128, 256, txtStart, _SCREEN);
	apply_surface(128, 312, txtOptions, _SCREEN);

	// Select Cursor (dynamic position)
	if(selectState == START)
	{
		apply_surface(100, 256+16, selectCursor, _SCREEN);
	}
	else if (selectState == OPTIONS)
	{
		apply_surface(100, 312+16, selectCursor, _SCREEN);
	}

	SDL_Flip( _SCREEN );
}

void Title::selectPrev()
{
	switch(selectState)
	{
	case START:
		selectState = OPTIONS; break;
	case OPTIONS:
		selectState = START; break;
	}
}

void Title::selectNext()
{
	switch(selectState)
	{
	case START:
		selectState = OPTIONS; break;
	case OPTIONS:
		selectState = START; break;
	}
}

Title::Select Title::getSelection()
{
	return selectState;
}
