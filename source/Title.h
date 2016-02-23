/*
The title screen.
*/
#ifndef Title_H
#define Title_H

#include "SDL/SDL.h"

class Title
{
public:
	enum Select {START, OPTIONS};
public:
	Title(SDL_Surface *_screen);
	~Title();
public:
	void redraw(); // redraws the title screen
	void selectPrev(); // selects previous title selection
	void selectNext(); // selects next title selection
	Select getSelection(); // returns the select state
private:
	Select selectState; // current state of Select
	SDL_Surface *_SCREEN; 
	SDL_Surface *background; 
	SDL_Surface *txtTetrii;
	SDL_Surface *txtStart;
	SDL_Surface *txtOptions; // opstions no longer shows options.  Now it shows the credits
	SDL_Surface *selectCursor; // cursor surface to show current selection
};

#endif

