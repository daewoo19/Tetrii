#ifndef Game_H
#define Game_H

#include "BlockType.h"
#include "GamePiece.h"
#include "GameField.h"
#include "SDL/SDL.h"
#include <set>
#include <list>

class Game
{
public:
	Game(SDL_Surface *_screen, int offset=0);
	~Game();
public:
	void redraw();
	void spawnNext();
	GamePiece * getGamePiece();
	//void rotateCW();
	//void rotateCCW();
	//void timerDrop();
private:
	void populateBag();
	BlockType pickNextBlock();
private:
	//BlockType field[10][20]; -- refactored into a class
	GameField *_FIELD;
	BlockType hold;
	std::list<BlockType> *upcoming;
	std::set<BlockType> *blockBag;
	// Active Pieces
	GamePiece *gamePiece;
	GamePieceI *pieceI;
	GamePieceO *pieceO;
	GamePieceL *pieceL;
	GamePieceJ *pieceJ;
	GamePieceS *pieceS;
	GamePieceZ *pieceZ;
	GamePieceT *pieceT;

	SDL_Surface *_SCREEN;
	SDL_Surface *fieldOverlay;

	int offset;
};

#endif

