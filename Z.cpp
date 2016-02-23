#include "GamePiece.h"
#include "_utils.h"

GamePieceZ::GamePieceZ(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-Z.png");
	mini = load_image("images/miniblock-Z.png");
	size = 3;
}

//void GamePieceZ::redraw()
//{
//	for(int col = 0; col != 3; ++col)
//	{
//		for(int row = 0; row != 3; ++row)
//		{
//			if(blocks[col][row] == Z)
//				apply_surface(x+col*20, y+row*20, block, _SCREEN);
//		}
//	}
//}

void GamePieceZ::rotateCCW()
{
	switch( rotationState )
	{
	case NORTH:	setWest(); break;
	case EAST:	setNorth(); break;
	case SOUTH:	setEast(); break;
	case WEST:	setSouth(); break;
	}

}

void GamePieceZ::rotateCW()
{
	switch( rotationState )
	{
	case NORTH:	setEast(); break;
	case EAST:	setSouth(); break;
	case SOUTH:	setWest(); break;
	case WEST:	setNorth(); break;
	}
}


void GamePieceZ::setNorth()
{
	blocks[0][0] = Z;	blocks[1][0] = Z;	blocks[2][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = Z;	blocks[2][1] = Z;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = NORTH;
}

void GamePieceZ::setEast()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = Z;
	blocks[0][1] = nil;	blocks[1][1] = Z;	blocks[2][1] = Z;
	blocks[0][2] = nil;	blocks[1][2] = Z;	blocks[2][2] = nil;
	rotationState = EAST;
}

void GamePieceZ::setSouth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;
	blocks[0][1] = Z;	blocks[1][1] = Z;	blocks[2][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = Z;	blocks[2][2] = Z;
	rotationState = SOUTH;
}

void GamePieceZ::setWest()
{
	blocks[0][0] = nil;	blocks[1][0] = Z;	blocks[2][0] = nil;
	blocks[0][1] = Z;	blocks[1][1] = Z;	blocks[2][1] = nil;
	blocks[0][2] = Z;	blocks[1][2] = nil;	blocks[2][2] = nil;
	rotationState = WEST;
}

