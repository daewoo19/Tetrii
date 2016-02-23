#include "GamePiece.h"
#include "_utils.h"

GamePieceO::GamePieceO(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-O.png");
	mini = load_image("images/miniblock-O.png");
	size = 2;
}

void GamePieceO::rotateCCW() { }

void GamePieceO::rotateCW() { }

void GamePieceO::setNorth()
{
	blocks[0][0] = O;	blocks[1][0] = O;
	blocks[0][1] = O;	blocks[1][1] = O;
}

