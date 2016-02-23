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

int GamePiece::getXOffset()
{
	return xOffset;   
}
int GamePiece::getYOffset()
{
	return yOffset;  
}


void GamePiece::timerDrop(bool fastDrop)
{
	
	if(collided(0,1))
	{
		setPosInMap();
		respawn();
        SDL_Event event;
        SDL_UserEvent userevent;

		userevent.type = SDL_USEREVENT;
        userevent.code = 101;

        event.type = SDL_USEREVENT;
        event.user = userevent;

        SDL_PushEvent(&event);
	}
	if (fastDrop)
		y += 20;
	else
		y += 10;
	yField = y / 20;
}


void GamePiece::setPosInMap()
{
	for (int col=0; col!=size; ++col)
	    for (int row=0; row !=size; ++row)
	        if (blocks[col][row] != nil)
               _FIELD->field[col + xField][row + yField] = blocks[col][row];
}


void GamePiece::rotateCCW()
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

void GamePiece::rotateCW()
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

// x = offset from a gamepiece's block's position
// y = offset from a gamepiece's block's position
bool GamePiece::collided(int x, int y )
{
     //test for field boundaries
	for(int col=0; col!=size; ++col)
		for(int row=0; row!=size; ++row)
			if( blocks[col][row] != nil 
			&& (xField + col + x> 9 || xField + col + x <0 || yField + row + y >19  || yField + row + y <0) )
			{
				return true;
            }
    //test for collisions with other blocks
	for(int col=0; col!=size; ++col)
		for(int row=0; row!=size; ++row)
			if(blocks[col][row] != nil 
			&& (_FIELD->field[xField + col + x][yField + row + y] != nil))
			{
				return true;
			}
	return false;
}

void GamePiece::shiftLeft()
{    
    if(collided(-1, 0))
        return; 

	x -= 20;
	--xField;
}

void GamePiece::shiftRight()
{
	if(collided(1,0))
		return;
        
 	x += 20;
	++xField;
}


void GamePiece::instantDrop()
{
 	for(int i=0; i!=20; ++i)
	{	
		if(collided(0,i))
		{
	 		yField += i-1;
	 		return;
		}
	}
}

void GamePiece::respawn()
{
	setNorth();
	x = 60;
	y = 0;
	xField = x/20;
	yField = y/20;
}

