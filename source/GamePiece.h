/*
Class for gamepieces.  
Pieces are able to more around on the field and beable to detect collisions with other blocks
*/

#ifndef GamePiece_H
#define GamePiece_H

#include "BlockType.h"
#include "GameField.h"
#include "SDL/SDL.h"

class GamePiece
{
public:
	GamePiece();
	virtual ~GamePiece();
	// rotates the  piece counter-clockwise.  Piece does wall kicks and floor kicks when necessary
	virtual void rotateCCW();
	// rotates the  piece clockwise.  Piece does wall kicks and floor kicks when necessary
	virtual void rotateCW();
	// redraws the piece on screen
	void redraw();
	// resets the positions of game piece
	virtual void respawn();
	// drops the piece half a space down at time increments.  Drops the piece full space down at quicker increments when fastDrop is enabled.
	void timerDrop(bool fastDrop);
	//shifts the  piece on space left if possible
	void shiftLeft();
	// shifts the  piece on space right if possible
	void shiftRight();
	// checks for the lowest free position in field and drops the piece there
	void instantDrop();
	// checks if the piece has collided with either the gamefield boundaries or other pieces at its current position + the x and y offset.
	bool collided(int x, int y);
	
	// applies  piece to the _FIELD the  based on its current position
	void setPosInMap();
	
	SDL_Surface *getBlock();
	SDL_Surface *getMini();
	
	// returns the x,y offsets
	int getXOffset();
	int getYOffset();

protected:
	// sets the blocks in the piece the predetermined positions
	virtual void setNorth()	{	}
	virtual void setEast()	{	}
	virtual void setSouth()	{	}
	virtual void setWest()	{	}
protected:
	enum RotationState {NORTH, EAST, SOUTH, WEST};
	RotationState rotationState;

	// Dimentions (width, height)
	int size;
	BlockType blocks[4][4];
	
	// Screen Coordinates
	int x;
	int xOffset;
	int y;
	int yOffset;
	
	// Field Coordinates
	int xField;
	int yField;

	GameField *_FIELD;
	
	SDL_Surface *_SCREEN;
	SDL_Surface *block;
	SDL_Surface *mini;
};

/*********************************************************************
Derived classes of GamePiece. They are mostly used to set different block layouts
*********************************************************************/

class GamePieceI : public GamePiece
{
public:
	GamePieceI(SDL_Surface *_screen, GameField *_field);
	//same as base class rotate but with extra wall kicks
	virtual void rotateCCW();
	virtual void rotateCW();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
};

class GamePieceO : public GamePiece
{
public:
	GamePieceO(SDL_Surface *_screen, GameField *_field);
	// O pieces do not rotate so these do nothing
	void rotateCCW();
	void rotateCW();
protected:
	virtual void setNorth();
};

class GamePieceL : public GamePiece
{
public:
	GamePieceL(SDL_Surface *_screen, GameField *_field);
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
};

class GamePieceJ : public GamePiece
{
public:
	GamePieceJ(SDL_Surface *_screen, GameField *_field);
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
};

class GamePieceS : public GamePiece
{
public:
	GamePieceS(SDL_Surface *_screen, GameField *_field);
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
};

class GamePieceZ : public GamePiece
{
public:
	GamePieceZ(SDL_Surface *_screen, GameField *_field);
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
};

class GamePieceT : public GamePiece
{
public:
	GamePieceT(SDL_Surface *_screen, GameField *_field);
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
};

#endif

