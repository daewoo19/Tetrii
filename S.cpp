#include "GamePiece.h"
#include "_utils.h"

GamePieceS::GamePieceS(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-S.png");
	mini = load_image("images/miniblock-S.png");
	size = 3;
	_BT = S;
}

//void GamePieceS::redraw()
//{
//
//}

void GamePieceS::rotateCCW()
{
	switch( rotationState )
	{
	case NORTH:	setWest(); break;
	case EAST:	setNorth(); break;
	case SOUTH:	setEast(); break;
	case WEST:	setSouth(); break;
	}

}

void GamePieceS::rotateCW()
{
	switch( rotationState )
	{
	case NORTH:	setEast(); break;
	case EAST:	setSouth(); break;
	case SOUTH:	setWest(); break;
	case WEST:	setNorth(); break;
	}
}


void GamePieceS::setNorth()
{
	blocks[0][0] = nil;	blocks[1][0] = S;	blocks[2][0] = S;
	blocks[0][1] = S;	blocks[1][1] = S;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = NORTH;
}

void GamePieceS::setEast()
{
	blocks[0][0] = nil;	blocks[1][0] = S;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = S;	blocks[2][1] = S;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = S;
	rotationState = EAST;
}

void GamePieceS::setSouth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = S;	blocks[2][1] = S;
	blocks[0][2] = S;	blocks[1][2] = S;	blocks[2][2] = nil;
	rotationState = SOUTH;
}

void GamePieceS::setWest()
{
	blocks[0][0] = S;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = S;	blocks[1][1] = S;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = S;	blocks[2][2] = nil;
	rotationState = WEST;
}

