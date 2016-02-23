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
	_BT = T;
}

//void GamePieceT::redraw()
//{
//	for(int col = 0; col != 3; ++col)
//	{
//		for(int row = 0; row != 3; ++row)
//		{
//			if(blocks[col][row] == T)
//				apply_surface(x+col*20, y+row*20, block, _SCREEN);
//		}
//	}
//}

void GamePieceT::rotateCCW()
{
	switch( rotationState )
	{
	case NORTH:	setWest(); break;
	case EAST:	setNorth(); break;
	case SOUTH:	setEast(); break;
	case WEST:	setSouth(); break;
	}
}

void GamePieceT::rotateCW()
{
	switch( rotationState )
	{
	case NORTH:	setEast(); break;
	case EAST:	setSouth(); break;
	case SOUTH:	setWest(); break;
	case WEST:	setNorth(); break;
	}
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

