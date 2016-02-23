#ifndef DropTimerParams_H
#define DropTimerParams_H

#include "SDL/SDL.h"

class DropTimerParams
{
public:
	DropTimerParams();

	Uint32 interval;

	Uint32 currentLevelInterval;

	static const Uint32 fastDropInterval = 25;
};

#endif

