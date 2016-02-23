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
	delete gameA;
}

void GameScreen::redraw()
{
	// Background
	apply_surface(0, 0, background, _SCREEN);

	gameA->redraw();
	
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

void GameScreen::cycleBackground()
{
	switch( rand() % 4 )
	{
	case 0:
		background = load_image("images/background-01.png");
		break;
	case 1:
		background = load_image("images/background-60.png");
		break;
	case 2:
		background = load_image("images/background-120.png");
		break;
	case 3:
		background = load_image("images/background-180.png");
		break;
	}
}


