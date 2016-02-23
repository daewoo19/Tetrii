/*
This class represents the game for 1 player.  
*/
#ifndef Game_H
#define Game_H

#include "BlockType.h"
#include "GamePiece.h"
#include "GameField.h"
#include "SDL/SDL.h"
#include "Blocks.h"
#include <set>
#include <list>
#include "SDL/SDL_ttf.h"

class Game
{
public:
	//*_screen is the image of the game field
	Game(SDL_Surface *_screen, int offset=0);
	~Game();
public:
	//redraws the entire game which consists of the game field, active piece, landed pieces, preview piece, hold pieces and score.
	void redraw();
	//picks the next piece to be spawned and has the gamepiece respawn as that piece
	void spawnNext();
	//returns the current gamepeice
	GamePiece * getGamePiece();
	//swaps the current gamepiece with the hold piece
	void hold();
	GameField *_FIELD;
private:
	//inserts all seven types of pieces into the bag
	void populateBag();
	//psuedo randomly picks the gamepiece to respawn
	BlockType pickNextBlock();
private:
	TTF_Font *font;
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
	
	GamePiece *holdPiece;
	
	//Blocks to apply to the field
	Blocks *gameBlocks;

	SDL_Surface *_SCREEN;
	SDL_Surface *fieldOverlay;
	SDL_Surface *txtScore;
	SDL_Color color;

	int offset;
};

#endif

