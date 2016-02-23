#include "Timer.h"
#include "DropTimerParams.h"
#include "SDL/SDL.h"

Uint32 dropTimerCallback(Uint32 interval, void *dropTimerParams)
{
        SDL_Event event;
        SDL_UserEvent userevent;

        /* In this example, our callback pushes an SDL_USEREVENT event
	           into the queue, and causes ourself to be called again at the
	           same interval: */

		DropTimerParams *params = (DropTimerParams*)dropTimerParams;

        userevent.type = SDL_USEREVENT;
        userevent.code = 100; // refer to tetrii.cpp for what this does

        event.type = SDL_USEREVENT;
        event.user = userevent;

        SDL_PushEvent(&event);
        return(params->interval);
}

