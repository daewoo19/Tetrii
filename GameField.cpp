#include "GameField.h"

GameField::GameField()
{
	for(int col = 0; col != 10; ++col)
	{
		for(int row = 0; row != 20; ++row)
		{
			field[col][row] = nil;
		}
	}
}

