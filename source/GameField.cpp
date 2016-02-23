#include "GameField.h"

GameField::GameField() : linesCleared(0), toNextLevel(10)
{
	for(int col = 0; col != 10; ++col)
	{
		for(int row = 0; row != 20; ++row)
		{
			field[col][row] = nil;
		}
	}
}

void GameField::flush()
{
	bool full[20];
	int dirty = 20; // number of rows to be cleared
	int col;
	int row;
	for( row = 0; row != 20; ++row )
	{
		full[row] = true;
		for( col = 0; col != 10; ++col )
		{
			if( field[col][row] == nil )
			{
				full[row] = false;
				--dirty;
				break;
			}
		}
	}
	linesCleared += dirty;
	toNextLevel -= dirty;
	// Check if we increase the game's level...
	if(toNextLevel <= 0)
	{
		toNextLevel += 10;
        SDL_Event event;
        SDL_UserEvent userevent;

        userevent.type = SDL_USEREVENT;
        userevent.code = 110;

        event.type = SDL_USEREVENT;
        event.user = userevent;

        SDL_PushEvent(&event);
	}
	while( dirty != 0 )
	{
		for(row = 19; row > 0; --row)
		{
			if( full[row] )
			{
				for(int fullrow = row; fullrow > 0; --fullrow)
				{
					full[fullrow] = full[fullrow-1];
					for( col = 0; col != 10; ++col )
					{
						if(fullrow == 0)
						{
							field[col][fullrow] = nil;
						}
						else
						{
							field[col][fullrow] = field[col][fullrow-1];
						}
					}
				}
			}
		}
		--dirty;
	}
}
