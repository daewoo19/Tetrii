#include "GamePiece.h"
#include "_utils.h"

GamePieceJ::GamePieceJ(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-J.png");
	mini = load_image("images/miniblock-J.png");
	size = 3;
}

//void GamePieceJ::redraw()
//{
//
//}

void GamePieceJ::rotateCCW()
{
	switch( rotationState )
	{
	case NORTH:	setWest(); break;
	case EAST:	setNorth(); break;
	case SOUTH:	setEast(); break;
	case WEST:	setSouth(); break;
	}

}

void GamePieceJ::rotateCW()
{
	switch( rotationState )
	{
	case NORTH:	setEast(); break;
	case EAST:	setSouth(); break;
	case SOUTH:	setWest(); break;
	case WEST:	setNorth(); break;
	}
}


void GamePieceJ::setNorth()
{
	blocks[0][0] = J;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = J;	blocks[1][1] = J;	blocks[2][1] = J;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = NORTH;
}

void GamePieceJ::setEast()
{
	blocks[0][0] = nil;	blocks[1][0] = J;	blocks[2][0] = J;
	blocks[0][1] = nil;	blocks[1][1] = J;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = J;	blocks[2][2] = nil;
	rotationState = EAST;
}

void GamePieceJ::setSouth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = J;	blocks[1][1] = J;	blocks[2][1] = J;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = J;
	rotationState = SOUTH;
}

void GamePieceJ::setWest()
{
	blocks[0][0] = nil;	blocks[1][0] = J;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = J;	blocks[2][1] = nil;
	blocks[0][2] = J;	blocks[1][2] = J;	blocks[2][2] = nil;
	rotationState = WEST;
}
