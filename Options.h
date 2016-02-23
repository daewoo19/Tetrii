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
	void redraw();
private:
	SDL_Surface *_SCREEN;
	SDL_Surface *background;
	SDL_Surface *txtOptions;
	SDL_Surface *selectCursor;
};

#endif

