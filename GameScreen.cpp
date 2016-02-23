#include "GameScreen.h"
#include "_utils.h"

GameScreen::GameScreen(SDL_Surface *_screen) : _SCREEN(_screen)
{
	// Load Images
	background = load_image("images/background-120.png");

	// State Variables
	gameA = new Game(_screen, 200);
}

GameScreen::~GameScreen()
{
	SDL_FreeSurface( background );
}

void GameScreen::redraw()
{
	// Background
	apply_surface(0, 0, background, _SCREEN);

	// Gamefield(s)
	//apply_surface(0, 0, fieldOverlay, _SCREEN);
	gameA->redraw();

	// Text
	//apply_surface(45, 90, txtTetrii, _SCREEN);
	//apply_surface(128, 256, txtStart, _SCREEN);
	//apply_surface(128, 312, txtOptions, _SCREEN);

	//// Select Cursor (dynamic position)
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

Game * GameScreen::getGame()
{
	return gameA;
}

GamePiece * GameScreen::getGamePiece()
{
	return gameA->getGamePiece();
}

//
//void Game::rotateCW()
//{
//	gameField->rotateCW();
//}
//
//void Game::rotateCCW()
//{
//	gameField->rotateCCW();
//}
//
//void Game::timerDrop()
//{
//	gameField->timerDrop();
//}

