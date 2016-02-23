#include "Tetrii.h"
#include "SDL/SDL.h"
#include "_utils.h"

void Tetrii::Init()
{
	// == INIT SDL ==
	_SCREEN = SDL_SetVideoMode( SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE );
    SDL_WM_SetCaption( "Tetrii", NULL );
	SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY, SDL_DEFAULT_REPEAT_INTERVAL);
	quit = false;
	
	// == INIT TIMER ==
	//dropTimer = new Timer();
	dropTimerParams = new DropTimerParams();
	dropTimer = SDL_AddTimer(50, dropTimerCallback, dropTimerParams);

	// == INIT Tetrii ==
	titleScreen = new Title(_SCREEN);
	optionsScreen = new Options(_SCREEN);
	state = TITLE;
}

Tetrii::Tetrii()
{
	Init();
	//dropTimer->start();
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
					//case SDLK_UP:
					//	break;
					//case SDLK_DOWN:
					//	break;
					//case SDLK_RETURN:
					//	switch( optionsScreen->getSelection() )
					//	{
					//	}
					}
					break;
				case GAME1P:
					switch( event.key.keysym.sym )
					{
					case SDLK_ESCAPE:	/* Pause and show menu */
						break;
					case SDLK_LSHIFT:	/* Hold */
						break;
					case SDLK_LCTRL:	/* Rotate CCW */
						gamePieceA->rotateCCW(); break;
					case SDLK_LALT:		/* Rotate CW */
						gamePieceA->rotateCW(); break;
					case SDLK_UP:		/* Instant Drop */
						break;
					case SDLK_DOWN:		/* Quick Drop */
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
					case 0:
						gamePieceA->timerDrop();
						break;
					// == GamePiece has "landed" ==
					case 1:
						gameA->spawnNext();
						gamePieceA = gameA->getGamePiece();
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
				//if (dropTimer->get_ticks() > 500)
				//{
				//	gameScreen->rotateCCW();
				//	dropTimer->start();
				//}
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

