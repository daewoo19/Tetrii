#include "Game.h"
#include "_utils.h"
#include <set>
#include <sstream>
#include <string>

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
	
	gameBlocks = new Blocks();
	gameBlocks->Init();

	blockBag = new std::set<BlockType>;
	upcoming = new std::list<BlockType>;

	populateBag();

	for(int i = 0; i != 14; ++i)
	{
		upcoming->push_back(pickNextBlock());
	}

	font =  TTF_OpenFont( "ariblk.ttf", 18 );
	color.r = 200;
	color.g = 200;
	color.b = 200;
	spawnNext();
	holdPiece = 0;
}

Game::~Game()
{
	SDL_FreeSurface( fieldOverlay );
	delete pieceI;
	delete pieceO;
	delete pieceL;
	delete pieceJ;
	delete pieceS;
	delete pieceZ;
	delete pieceT;
	delete gameBlocks;
	delete blockBag;
	delete upcoming;
	
}

// Utility function to produce a string from a number.
// Found at... http://www.parashift.com/c++-faq-lite/misc-technical-issues.html
inline std::string stringify(long x)
{
  std::ostringstream o;
  o << x;
  return o.str();
}

void Game::redraw()
{
	// Field
	apply_surface(offset, 0, fieldOverlay, _SCREEN);

	// Score
	std::string score;
	score = stringify( _FIELD->linesCleared );
	txtScore	= TTF_RenderText_Solid(font, score.c_str(), color);
	apply_surface(offset+310, 0, txtScore, _SCREEN);


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
	if(holdPiece != 0)
	{
		mini = holdPiece->getMini();
		apply_surface(20+offset, 35, mini, _SCREEN);
	}
	
	//pieces already on field
	for(int col = 0; col != 10; ++col)
	{
		for(int row = 0; row != 20; ++row)
		{
			if(_FIELD->field[col][row] != nil)
			    switch(_FIELD->field[col][row])
			    {
		     	    case I:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->I, _SCREEN); break;
	                case O:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->O, _SCREEN); break;
	                case L:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->L, _SCREEN); break;
                    case J:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->J, _SCREEN); break;
	                case S:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->S, _SCREEN); break;
	                case Z:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->Z, _SCREEN); break;
                    case T:	apply_surface(gamePiece->getXOffset()+col*20, gamePiece->getYOffset()+row*20, gameBlocks->T, _SCREEN); break;
                }
        }
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

void Game::hold()
{
	GamePiece *returnPiece = holdPiece;
	holdPiece = gamePiece;
	if(returnPiece == 0)
	{
		spawnNext();
		return;
	}
	gamePiece = returnPiece;
	return;
}


