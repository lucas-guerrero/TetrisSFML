#ifndef GRID_GAME_DEF
#define GRID_GAME_DEF

#include "VarUtils.h"
#include <array>

class GridGame
{
public:
	int grid[GAME_WIDTH][GAME_HEIGHT];

	int checkLine();

	bool* checkNeighbor(int indexX, int indexY);
	bool isEmbedded(int indexX, int indexY);

	bool isEndGame();

	void initGrid();

private:
	void deleteLine(int indiceLine);
};

#endif // !GRID_GAME_DEF
