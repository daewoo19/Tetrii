#include "Tetrii.h"
#include "SDL/SDL.h"
#include "SDL/SDL_ttf.h"

int main( int argc, char* args[] )
{
	SDL_Init( SDL_INIT_EVERYTHING );
	TTF_Init();

	Tetrii *tetriiInstance = new Tetrii();
	SDL_Quit();

	delete tetriiInstance;

	return 0;    
}

