/*
Holds all the games of each player..
*/
#ifndef GameScreen_H
#define GameScreen_H

#include "SDL/SDL.h"
#include "Game.h"
#include "GamePiece.h"
#include "GameField.h"

class GameScreen
{
public:
	GameScreen(SDL_Surface *_screen);
	~GameScreen();
public:
	// draws the background and everything else to the screen
	void redraw();
	
	Game * getGame();

	// returns the active gamepiece
	GamePiece * getGamePiece();
	
	// psuedo randomly changes the background
	void cycleBackground();
        
private:
	// Select selectState;
	SDL_Surface *_SCREEN;
	SDL_Surface *background;
private:
	Game *gameA;
};

#endif


