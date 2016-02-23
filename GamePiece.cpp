#include "GamePiece.h"
#include "SDL/SDL.h"
#include "_utils.h"

GamePiece::GamePiece() : x(0), y(0), rotationState(NORTH), xOffset(300), yOffset(25)
{
}

GamePiece::~GamePiece()
{
	SDL_FreeSurface( block );
	SDL_FreeSurface( mini );
}

void GamePiece::redraw()
{
	for(int col = 0; col != size; ++col)
	{
		for(int row = 0; row != size; ++row)
		{
			if(blocks[col][row] != nil)
				apply_surface(xOffset+x+col*20, yOffset+y+row*20, block, _SCREEN);
		}
	}
}

SDL_Surface *GamePiece::getBlock()
{
	return block;
}

SDL_Surface *GamePiece::getMini()
{
	return mini;
}

void GamePiece::timerDrop()
{
	/*
	//==NEW STUFF, TEST IT!!==//
	for(int col=0; col!=size; ++col)
		for(int row=0; row!=size; ++row)
			if(_FIELD->field[xField + col][yField + row] != nil)
			{
				_FIELD->field[xField + col ][yField + row+1] = blocks[col][row];
				_FIELD->field[xField + col][yField + row] = nil;
			}
	*/
	y += 20;
	yField = y / 20;
	if(yField == 19)
	{
		respawn();
        SDL_Event event;
        SDL_UserEvent userevent;

		userevent.type = SDL_USEREVENT;
        userevent.code = 1;

        event.type = SDL_USEREVENT;
        event.user = userevent;

        SDL_PushEvent(&event);
	}
}
/**
rotateCW()
{
	BlockType temp[size][size];
	//temp = rotated version of current state
	if (!collides(0,0) ; //just rotate, good! blocks = temp;
	if (!collides(1,0) ; //blocks = temp, shift right;
	if (!collides(-1,0) ; //blocks = temp, shift left;
	//else failed
}
rotateCCW()
{
	BlockType temp[size][size];
	//temp = rotated version of current state
	if (!collides(0,0) ; //just rotate, good! blocks = temp;
	if (!collides(1,0) ; //blocks = temp, 1 kick right;
	if (!collides(-1,0) ; //blocks = temp, 1 kick left;
	//else failed
}
*/

bool GamePiece::collides(int x, int y, BlockType b[4][4] )
{
     //test for map boundaries
	for(int col=0; col!=size; ++col)
		for(int row=0; row!=size; ++row)
			if(_FIELD->field[xField + col][yField + row] != nil 
			&& (xField + col + x>= 9 || xField + col + x <=0 || yField + row + y >=19 ))
			{
				return true;
            	}
    //test for collisions with other blocks
//	for(int col=0; col!=size; ++col)
//		for(int row=0; row!=size; ++row)
//			if(_FIELD->field[xField + col][yField + row] != nil 
//			&& (_FIELD->field[xField + col + x][yField + row + y] != nil))
//			{
//				return true;
//			}
	return false;
}

void GamePiece::shiftLeft()
{    
    if(collides(-1, 0, blocks))
        return; 

    for(int col=0; col!=size; ++col)
		for(int row=0; row!=size; ++row)
			if(_FIELD->field[xField + col][yField + row] != nil)
			{
                _FIELD->field[xField + col - 1][yField + row] = blocks[col][row];
                _FIELD->field[xField + col][yField + row] = nil;
            }
	x -= 20;
	--xField;
}

void GamePiece::shiftRight()
{
	if(collides(1,0, blocks))
		return;
        
	for(int col=size; col!=0; --col)
		for(int row=0; row!=size; ++row)
			if(_FIELD->field[xField + col][yField + row] != nil)
			{
			_FIELD->field[xField + col + 1][yField + row] = blocks[row][col];
			_FIELD->field[xField + col][yField + row] = nil;
			}
 	x += 20;
	++xField;
}

void GamePiece::respawn()
{
	setNorth();
	
	//make the gamefield contain the blocks
	for (int col=0; col!=size; ++col)
	    for (int row=0; row !=size; ++row)
            _FIELD->field[col + 3][row] = blocks[col][row];
            
	x = 60;
	y = 0;
	xField = x/20;
	yField = y/20;
}

