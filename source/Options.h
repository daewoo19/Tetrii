/*
This class is used to display the game credits instead of options
*/
#ifndef Options_H
#define Options_H

#include "SDL/SDL.h"

class Options
{
private:
	enum Select {START, OPTIONS};
	Select selectState;
public:
	Options(SDL_Surface *_screen);
	~Options();
public:
	void redraw();// redraws the credit screen
private:
	SDL_Surface *_SCREEN;
	SDL_Surface *background;
	// object holds the title of this screen, which happens to be "credits", not "options"
	SDL_Surface *txtOptions;
	SDL_Surface *txtCredits1;
	SDL_Surface *txtCredits2;
	SDL_Surface *selectCursor;
};

#endif

