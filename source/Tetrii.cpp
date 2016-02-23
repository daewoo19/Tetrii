#include "Tetrii.h"
#include "SDL/SDL.h"
#include "_utils.h"
#include <ctime>

#define INIT_DROP_SPEED 500

void EnableKeyRepeat()
{
	SDL_EnableKeyRepeat(100, 20);
}

void DisableKeyRepeat()
{
	SDL_EnableKeyRepeat(0, 0);
}

void Tetrii::Init()
{
	srand(time(0));

	// == INIT SDL ==
	_SCREEN = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    SDL_WM_SetCaption( "Tetrii", NULL );
	EnableKeyRepeat();
	quit = false;
	
	// == INIT TIMER ==
	//dropTimer = new Timer();
	dropTimerParams = new DropTimerParams();
	dropTimerParams->currentLevelInterval = INIT_DROP_SPEED;
	dropTimerParams->interval = dropTimerParams->currentLevelInterval;
	dropTimer = SDL_AddTimer(dropTimerParams->interval, dropTimerCallback, dropTimerParams);

	// == INIT Tetrii ==
	titleScreen = new Title(_SCREEN);
	optionsScreen = new Options(_SCREEN);
	state = TITLE;
	fastDrop = false;

}

Tetrii::Tetrii()
{
	Init();
	// == LOOP ==
	while( quit == false )
    { 
        //While there's an event to handle
        while( quit == false && SDL_WaitEvent( &event ) )
        {
			switch( event.type )
			{
			case SDL_QUIT:
				quit = true; break;
			case SDL_KEYUP:
				switch( state )
				{
				case GAME1P:
					switch( event.key.keysym.sym )
					{
					case SDLK_DOWN:		/* Quick Drop */
						EnableKeyRepeat();	// restore down_key functionality
						dropTimerParams->interval = dropTimerParams->currentLevelInterval;
						fastDrop = false;
						break;
					case SDLK_UP:		/* Instant Drop */
						EnableKeyRepeat();	// restore up_key functionality
						break;
					}
					break;
				}
				break;
			case SDL_KEYDOWN:
				switch( state )
				{
				case TITLE:
					switch( event.key.keysym.sym )
					{
					case SDLK_UP:
						titleScreen->selectPrev(); break;
					case SDLK_DOWN:
						titleScreen->selectNext(); break;
					case SDLK_RETURN:
						switch( titleScreen->getSelection() )
						{
						// == INIT FOR GAME ==
						case Title::START:
							state = GAME1P;
							gameScreen = new GameScreen(_SCREEN);
							gameA = gameScreen->getGame();
							gamePieceA = gameScreen->getGamePiece();

							dropTimerParams->currentLevelInterval = INIT_DROP_SPEED;
							dropTimerParams->interval = dropTimerParams->currentLevelInterval;
							fastDrop = false;
							break;
						case Title::OPTIONS:
							state = OPTIONS; break;
						}
					}
					break;
				case OPTIONS:
					switch( event.key.keysym.sym )
					{
					case SDLK_ESCAPE:
						state = TITLE; break;
					}
					break;
				case GAME1P:
					switch( event.key.keysym.sym )
					{
					case SDLK_ESCAPE:	/* Pause and show menu */
						break;
					case SDLK_LSHIFT:	/* Hold */
						gameA->hold();
						gamePieceA = gameA->getGamePiece();
						gamePieceA->respawn();
						break;
					case SDLK_LCTRL:	/* Rotate CCW */
						gamePieceA->rotateCCW(); break;
					case SDLK_LALT:		/* Rotate CW */
						gamePieceA->rotateCW(); break;
					case SDLK_UP:		/* Instant Drop */
						DisableKeyRepeat();		// disable up_key functionality, prevents suicide
						gamePieceA->instantDrop();
						break;
					case SDLK_DOWN:		/* Quick Drop */
						DisableKeyRepeat();		// disable down_key functionality, prevents cpu overusage when quick-drop is in effect
						dropTimerParams->interval = dropTimerParams->fastDropInterval;
						fastDrop = true;
						SDL_RemoveTimer(dropTimer);
						dropTimer = SDL_AddTimer(dropTimerParams->interval, dropTimerCallback, dropTimerParams);
						break;
					case SDLK_LEFT:
						gamePieceA->shiftLeft(); break;
					case SDLK_RIGHT:
						gamePieceA->shiftRight(); break;
					}
				}
			case SDL_USEREVENT:
				switch( state )
				{
				case GAME1P:
					switch( event.user.code )
					{
					// == Timer Events (produced by timer callbacks) ==
					case 100:
						gamePieceA->timerDrop(fastDrop);
						break;
					// == GamePiece has "landed" ==
					case 101:
						gameA->spawnNext();
						gameA->_FIELD->flush();
						gamePieceA = gameA->getGamePiece();
						if(gamePieceA->collided(0,0))
						{
							state = TITLE;
						}
						break;
					// == 10 (or more) lines have been cleared... "Level-up" (faster drop speed) ==
					case 110:
						if( dropTimerParams->currentLevelInterval - 50 > 25)
						{
							dropTimerParams->currentLevelInterval -= 50;
							dropTimerParams->interval = dropTimerParams->currentLevelInterval;
						}
						else
						{
							dropTimerParams->currentLevelInterval = 25;
							dropTimerParams->interval = dropTimerParams->currentLevelInterval;
						}
						gameScreen->cycleBackground();
						break;
					}
				}
				break;
			}
			// Redraw things.
			switch( state )
			{
			case TITLE:
				titleScreen->redraw(); break;
			case OPTIONS:
				optionsScreen->redraw(); break;
			case GAME1P:
				gameScreen->redraw(); break;
			}
        }
    }
}

Tetrii::~Tetrii()
{
	delete titleScreen;
	delete optionsScreen;
	delete gameScreen;
	delete dropTimerParams;
}


