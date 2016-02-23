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
	void redraw();
	void selectPrev();
	void selectNext();
	Select getSelection();
private:
	Select selectState;
	SDL_Surface *_SCREEN;
	SDL_Surface *background;
	SDL_Surface *txtTetrii;
	SDL_Surface *txtStart;
	SDL_Surface *txtOptions;
	SDL_Surface *selectCursor;
};

#endif

