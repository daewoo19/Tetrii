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

void GamePieceI::rotateCCW()
{
    //back up the original state
    BlockType backup[4][4];
    for (int i =0; i!=size; ++i)
        for(int j = 0; j!=size; ++j)
            backup[i][j]=blocks[i][j];
            
	//rotate it
	switch( rotationState )
	{
	case NORTH:	setWest(); break;
	case EAST:	setNorth(); break;
	case SOUTH:	setEast(); break;
	case WEST:	setSouth(); break;
	}

	if (!collided(0,0)) ; //rotate is good!
	else if (!collided(1,0)) //kick right
	    {
           x += 20;
	       ++xField; 
        }
	else if (!collided(-1,0)) //kick left
	    {
           x -= 20;
	       --xField; 
        }
	else if (!collided(2,0)) //2 kicks right
	    {
           x += 40;
	       ++xField; 
	       ++xField; 
        }
	else if (!collided(-2,0)) //2 kicks left
	    {
           x -= 40;
	       --xField;
	       --xField;
        }
	else if (!collided(0,-1)) //floor kick
	    {
           y -= 20;
	       --yField; 
        }
	else //failed, don't rotate
	{
        for (int i =0; i!=size; ++i)
            for(int j = 0; j!=size; ++j)
                blocks[i][j]=backup[i][j];
    }
}

void GamePieceI::rotateCW()
{
    //back up the original state
    BlockType backup[4][4];
    for (int i =0; i!=size; ++i)
        for(int j = 0; j!=size; ++j)
            backup[i][j]=blocks[i][j];
            
	//rotate it
	switch( rotationState )
	{
	case NORTH:	setEast(); break;
	case EAST:	setSouth(); break;
	case SOUTH:	setWest(); break;
	case WEST:	setNorth(); break;
	}

	if (!collided(0,0)) ; //rotate is good!
	else if (!collided(1,0)) //kick right
	    {
           x += 20;
	       ++xField; 
        }
	else if (!collided(-1,0)) //kick left
	    {
           x -= 20;
	       --xField; 
        }
	else if (!collided(2,0)) //2 kicks right
	    {
           x += 40;
	       ++xField; 
	       ++xField; 
        }
	else if (!collided(-2,0)) //2 kicks left
	    {
           x -= 40;
	       --xField;
	       --xField;
        }
	else if (!collided(0,-1)) //floor kick
	    {
           y -= 20;
	       --yField; 
        }
	else //failed, don't rotate
	{
        for (int i =0; i!=size; ++i)
            for(int j = 0; j!=size; ++j)
                blocks[i][j]=backup[i][j];
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

