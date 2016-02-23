#include "Game.h"
#include "_utils.h"
#include <set>

Game::Game(SDL_Surface *_screen, int offset) : _SCREEN(_screen), offset(offset)
{
	fieldOverlay = load_image("images/field1P.png");
	_FIELD = new GameField();
	pieceI = new GamePieceI(_screen, _FIELD);
	pieceO = new GamePieceO(_screen, _FIELD);
	pieceL = new GamePieceL(_screen, _FIELD);
	pieceJ = new GamePieceJ(_screen, _FIELD);
	pieceS = new GamePieceS(_screen, _FIELD);
	pieceZ = new GamePieceZ(_screen, _FIELD);
	pieceT = new GamePieceT(_screen, _FIELD);

	blockBag = new std::set<BlockType>;
	upcoming = new std::list<BlockType>;

	populateBag();

	for(int i = 0; i != 14; ++i)
	{
		upcoming->push_back(pickNextBlock());
	}

	spawnNext();
	hold = nil;
}

Game::~Game()
{
	SDL_FreeSurface( fieldOverlay );
}

void Game::redraw()
{
	// Field
	apply_surface(offset, 0, fieldOverlay, _SCREEN);

	// Preview Pieces
	SDL_Surface *mini;
	typedef std::list<BlockType>::const_iterator IterList;
	IterList preview = upcoming->begin();
	for(int i = 0; i != 6; ++i)
	{
		switch(*preview)
		{
		case I:	mini = pieceI->getMini(); break;
		case O:	mini = pieceO->getMini(); break;
		case L:	mini = pieceL->getMini(); break;
		case J:	mini = pieceJ->getMini(); break;
		case S:	mini = pieceS->getMini(); break;
		case Z:	mini = pieceZ->getMini(); break;
		case T:	mini = pieceT->getMini(); break;
		}
		apply_surface(320+offset, 35+(i*60), mini, _SCREEN);
		++preview;
	}

	// Hold Piece
	if(hold != nil)
	{
		switch(hold)
		{
		case I:	mini = pieceI->getMini(); break;
		case O:	mini = pieceO->getMini(); break;
		case L:	mini = pieceL->getMini(); break;
		case J:	mini = pieceJ->getMini(); break;
		case S:	mini = pieceS->getMini(); break;
		case Z:	mini = pieceZ->getMini(); break;
		case T:	mini = pieceT->getMini(); break;
		}
		apply_surface(20+offset, 35, mini, _SCREEN);
	}

	// Active Player Piece
	gamePiece->redraw();
}

void Game::populateBag()
{
	blockBag->insert(I);
	blockBag->insert(O);
	blockBag->insert(L);
	blockBag->insert(J);
	blockBag->insert(S);
	blockBag->insert(Z);
	blockBag->insert(T);
}

BlockType Game::pickNextBlock()
{
	typedef std::set<BlockType>::iterator Iter;
	typedef std::set<BlockType>::size_type ST;
	ST size = blockBag->size();
	ST pick = rand() % size;
	Iter iter = blockBag->begin();
	for(ST i = 0; i != pick; ++i)
	{
		++iter;
	}
	BlockType result = *iter;
	blockBag->erase(iter);
	if( blockBag->size() == 0 )
	{
		populateBag();
	}
	return result;
}

void Game::spawnNext()
{
	BlockType next = upcoming->front();
	upcoming->pop_front();
	upcoming->push_back(pickNextBlock());
	switch(next)
	{
		case I:	gamePiece = pieceI; break;
		case O:	gamePiece = pieceO; break;
		case L:	gamePiece = pieceL; break;
		case J:	gamePiece = pieceJ; break;
		case S:	gamePiece = pieceS; break;
		case Z:	gamePiece = pieceZ; break;
		case T:	gamePiece = pieceT; break;
	}
	gamePiece->respawn();
}

GamePiece * Game::getGamePiece()
{
	return gamePiece;
}
//
//void Game::rotateCW()
//{
//	gamePiece->rotateCW();
//}
//
//void Game::rotateCCW()
//{
//	gamePiece->rotateCCW();
//}
//
//void Game::timerDrop()
//{
//	gamePiece->timerDrop();
//}

