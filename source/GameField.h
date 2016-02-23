/* This class contains the gamefield that the tetrii pieces will move around and land it */

#ifndef GameField_H
#define GameField_H

#include "BlockType.h"
#include "SDL/SDL.h"

class GameField
{
public:
	GameField();
	BlockType field[10][20];// Holds all the blocks which have landed.

	long linesCleared;
	int toNextLevel;

	// Clears any row full of pieces and drops everything down.
	void flush();
};


#endif


