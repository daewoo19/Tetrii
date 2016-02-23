#ifndef GamePiece_H
#define GamePiece_H

#include "BlockType.h"
#include "GameField.h"
#include "SDL/SDL.h"

//class GameField;	// Circular reference break.

class GamePiece
{
public:
	GamePiece();
	~GamePiece();
	virtual void rotateCCW()=0;
	virtual void rotateCW()=0;
	void redraw();
	virtual void respawn();
	void timerDrop();
	void shiftLeft();
	void shiftRight();
	bool collides(int x, int y);
	SDL_Surface *getBlock();
	SDL_Surface *getMini();
protected:
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

    BlockType _BT;

	GameField *_FIELD;
	SDL_Surface *_SCREEN;

	SDL_Surface *block;
	SDL_Surface *mini;
};

class GamePieceI : public GamePiece
{
public:
	GamePieceI(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
private:
	//BlockType blocks[4][4];
};

class GamePieceO : public GamePiece
{
public:
	GamePieceO(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
private:
	//BlockType blocks[2][2];
};

class GamePieceL : public GamePiece
{
public:
	GamePieceL(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
private:
	//BlockType blocks[3][3];
};

class GamePieceJ : public GamePiece
{
public:
	GamePieceJ(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
private:
	//BlockType blocks[3][3];
};

class GamePieceS : public GamePiece
{
public:
	GamePieceS(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
private:
	//BlockType blocks[3][3];
};

class GamePieceZ : public GamePiece
{
public:
	GamePieceZ(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
private:
	//BlockType blocks[3][3];
};

class GamePieceT : public GamePiece
{
public:
	GamePieceT(SDL_Surface *_screen, GameField *_field);
	virtual void rotateCCW();
	virtual void rotateCW();
	//virtual void redraw();
protected:
	virtual void setNorth();
	virtual void setEast();
	virtual void setSouth();
	virtual void setWest();
private:
	//BlockType blocks[3][3];
};

#endif

