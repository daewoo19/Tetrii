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

	txtOptions	= TTF_RenderText_Solid(font, "Options", color);

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
}

void Options::redraw()
{
	// Background
	apply_surface(0, 0, background, _SCREEN);

	// Text
	apply_surface(600, 30, txtOptions, _SCREEN);
	//apply_surface(128, 256, txtStart, _SCREEN);
	//apply_surface(128, 312, txtOptions, _SCREEN);

	// Select Cursor (dynamic position)
	//if(selectState == START)
	//{
	//	apply_surface(100, 256+16, selectCursor, _SCREEN);
	//}
	//else if (selectState == OPTIONS)
	//{
	//	apply_surface(100, 312+16, selectCursor, _SCREEN);
	//}

	SDL_Flip( _SCREEN );
}
//
//void Title::selectPrev()
//{
//	switch(selectState)
//	{
//	case START:
//		selectState = OPTIONS; break;
//	case OPTIONS:
//		selectState = START; break;
//	}
//}
//
//void Title::selectNext()
//{
//	switch(selectState)
//	{
//	case START:
//		selectState = OPTIONS; break;
//	case OPTIONS:
//		selectState = START; break;
//	}
//}

//Options::Select Options::getSelection()
//{
//	return selectState;
//}

