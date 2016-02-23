#include "GamePiece.h"
#include "_utils.h"

GamePieceT::GamePieceT(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-T.png");
	mini = load_image("images/miniblock-T.png");
	size = 3;
}

void GamePieceT::setNorth()
{
	blocks[0][0] = nil;	blocks[1][0] = T;	blocks[2][0] = nil;
	blocks[0][1] = T;	blocks[1][1] = T;	blocks[2][1] = T;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = NORTH;
}

void GamePieceT::setEast()
{
	blocks[0][0] = nil;	blocks[1][0] = T;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = T;	blocks[2][1] = T;
	blocks[0][2] = nil;	blocks[1][2] = T;	blocks[2][2] = nil;
	rotationState = EAST;
}

void GamePieceT::setSouth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = T;	blocks[1][1] = T;	blocks[2][1] = T;
	blocks[0][2] = nil;	blocks[1][2] = T;	blocks[2][2] = nil;
	rotationState = SOUTH;
}

void GamePieceT::setWest()
{
	blocks[0][0] = nil;	blocks[1][0] = T;	blocks[2][0] = nil;
	blocks[0][1] = T;	blocks[1][1] = T;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = T;	blocks[2][2] = nil;
	rotationState = WEST;
}

