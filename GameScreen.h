#ifndef GameScreen_H
#define GameScreen_H

#include "SDL/SDL.h"
#include "Game.h"
#include "GamePiece.h"
#include "GameField.h"

class GameScreen
{
public:
//	enum Select {START, OPTIONS};
public:
	GameScreen(SDL_Surface *_screen);
	~GameScreen();
public:
	void redraw();
	// TODO: Refactor getGame such that it gets the Game of player 1 or player 2
	Game * getGame();
	// TODO: Refactor getGamePiece such that it gets the GamePiece of player 1 or player 2
	GamePiece * getGamePiece();
	//void rotateCW();
	//void rotateCCW();
	//void timerDrop();
	//void selectPrev();
	//void selectNext();
	//Select getSelection();

        
private:
	//Select selectState;
	SDL_Surface *_SCREEN;
	SDL_Surface *background;
private:
	Game *gameA;
};

#endif


