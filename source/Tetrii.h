/*
Tetrii class. The various states of the game can be changed from here.  This class will check the key states and 
allow for user input from the keyboard to control the game.
*/
#ifndef Tetrii_H
#define Tetrii_H

#include "Title.h"
#include "Options.h"
#include "Timer.h"
#include "DropTimerParams.h"
#include "GameScreen.h"
#include "Game.h"
#include "GamePiece.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

class Tetrii
{
public:
	Tetrii(); // main event loop is in here
	~Tetrii();
public:
	void Init(); // Initializes all the data members
public:
	enum State { TITLE, OPTIONS, GAME1P, GAME2P };
	State state;

private:
	Title *titleScreen;
	Options *optionsScreen;
	GameScreen *gameScreen;
	Game *gameA;			// Player 1's Game
	Game *gameB;			// Player 2's Game
	GamePiece *gamePieceA;	// Player 1's GamePiece
	GamePiece *gamePieceB;	// Player 2's GamePiece (unused)
private:
	//Timer * dropTimer;
	SDL_TimerID dropTimer;
	DropTimerParams *dropTimerParams;
private:
	bool quit; //to exit the game
	bool fastDrop; 
private:
	SDL_Event event;
	SDL_Surface *_SCREEN;
private:
	static const int SCREEN_WIDTH = 800;
	static const int SCREEN_HEIGHT = 450;
	static const int SCREEN_BPP = 32;
};

#endif

