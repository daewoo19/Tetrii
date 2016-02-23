#include "GamePiece.h"
#include "_utils.h"

GamePieceI::GamePieceI(SDL_Surface *_screen, GameField *_field)
{
	_SCREEN = _screen;
	_FIELD = _field;
	setNorth();
	block = load_image("images/block-I.png");
	mini = load_image("images/miniblock-I.png");
	size = 4;
}

//void GamePieceI::redraw()
//{
//	for(int col = 0; col != 4; ++col)
//	{
//		for(int row = 0; row != 4; ++row)
//		{
//			if(blocks[col][row] == I)
//				apply_surface(x+col*20, y+row*20, block, _SCREEN);
//		}
//	}
//}

void GamePieceI::rotateCCW()
{
	switch( rotationState )
	{
	case NORTH:	setWest(); break;
	case EAST:	setNorth(); break;
	case SOUTH:	setEast(); break;
	case WEST:	setSouth(); break;
	}

}

void GamePieceI::rotateCW()
{
	switch( rotationState )
	{
	case NORTH:	setEast(); break;
	case EAST:	setSouth(); break;
	case SOUTH:	setWest(); break;
	case WEST:	setNorth(); break;
	}
}

void GamePieceI::setNorth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;	blocks[3][0] = nil;
	blocks[0][1] = I;	blocks[1][1] = I;	blocks[2][1] = I;	blocks[3][1] = I;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = nil;	blocks[3][2] = nil;
	blocks[0][3] = nil;	blocks[1][3] = nil;	blocks[2][3] = nil;	blocks[3][3] = nil;
	rotationState = NORTH;
}

void GamePieceI::setEast()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = I;	blocks[3][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = nil;	blocks[2][1] = I;	blocks[3][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = nil;	blocks[2][2] = I;	blocks[3][2] = nil;
	blocks[0][3] = nil;	blocks[1][3] = nil;	blocks[2][3] = I;	blocks[3][3] = nil;
	rotationState = EAST;
}

void GamePieceI::setSouth()
{
	blocks[0][0] = nil;	blocks[1][0] = nil;	blocks[2][0] = nil;	blocks[3][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = nil;	blocks[2][1] = nil;	blocks[3][1] = nil;
	blocks[0][2] = I;	blocks[1][2] = I;	blocks[2][2] = I;	blocks[3][2] = I;
	blocks[0][3] = nil;	blocks[1][3] = nil;	blocks[2][3] = nil;	blocks[3][3] = nil;
	rotationState = SOUTH;
}

void GamePieceI::setWest()
{
	blocks[0][0] = nil;	blocks[1][0] = I;	blocks[2][0] = nil;	blocks[3][0] = nil;
	blocks[0][1] = nil;	blocks[1][1] = I;	blocks[2][1] = nil;	blocks[3][1] = nil;
	blocks[0][2] = nil;	blocks[1][2] = I;	blocks[2][2] = nil;	blocks[3][2] = nil;
	blocks[0][3] = nil;	blocks[1][3] = I;	blocks[2][3] = nil;	blocks[3][3] = nil;
	rotationState = WEST;
}

