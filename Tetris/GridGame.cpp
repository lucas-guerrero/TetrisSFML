#include "GridGame.h"

void GridGame::transpose(TetrominoGame& tetro)
{
	int indiceX = tetro.dx / SIZE_PIXELS;
	int indiceY = tetro.dy / SIZE_PIXELS;

	array<sf::Vector2i, 4> tetroTmp =  tetro.tetro->getTetroActual();

	for (int i = 0; i < 4; ++i)
	{
		grid[indiceX + tetroTmp[i].x][indiceY + tetroTmp[i].y] = 1;
	}
}

void GridGame::checkLine()
{
	int j = GAME_HEIGHT - 1;
	while (j >= 0)
	{
		int i = 0;
		while (grid[i][j] != 0 && i < GAME_WIDTH)
			++i;
		if (i >= GAME_WIDTH)
			deleteLine(j);
		else
			--j;
	}
}

void GridGame::deleteLine(int indiceLine)
{
	for (int j = indiceLine; j >= 0; --j)
	{
		for (int i = 0; i < GAME_WIDTH; ++i)
			if (j == 0)
				grid[i][j] = 0;
			else
				grid[i][j] = grid[i][j - 1];
	}
}