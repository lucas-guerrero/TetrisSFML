#ifndef GRID_GAME_DEF
#define GRID_GAME_DEF
#include "VarUtils.h"
#include "TetrominoGame.h"

class GridGame
{
public:
	int grid[GAME_WIDTH][GAME_HEIGHT];

	void transpose(TetrominoGame& tetro);

	void checkLine();

private:
	void deleteLine(int indiceLine);
};

#endif // !GRID_GAME_DEF
