#include "GamePiece.h"
#include "_utils.h"

GamePieceL::GamePieceL(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-L.png");
	mini = load_image("images/miniblock-L.png");
	size = 3;
}

void GamePieceL::setNorth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = L;
	blocks[0][1] = L;	blocks[1][1] = L;	blocks[2][1] = L;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = NORTH;
}

void GamePieceL::setEast()
{
	blocks[0][0] = nil;	blocks[1][0] = L;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = L;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = L;	blocks[2][2] = L;
	rotationState = EAST;
}

void GamePieceL::setSouth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = L;	blocks[1][1] = L;	blocks[2][1] = L;
	blocks[0][2] = L;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = SOUTH;
}

void GamePieceL::setWest()
{
	blocks[0][0] = L;	blocks[1][0] = L;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = L;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = L;	blocks[2][2] = nil;
	rotationState = WEST;
}

