#ifndef GRID_GAME_DEF
#define GRID_GAME_DEF

#include "VarUtils.h"
#include <array>
#include <iostream>

class GridGame
{
public:
	int grid[GAME_WIDTH][GAME_HEIGHT];

	int checkLine();

	bool* checkNeighbor(int indexX, int indexY);
	bool isEmbedded(int indexX, int indexY);

	bool isEndGame();

	void affich() {
		for (int i = 0; i < GAME_HEIGHT; ++i) {
			for (int j = 0; j < GAME_WIDTH; ++j)
				std::cout << grid[j][i] << " ";
			std::cout << std::endl;
		}
		std::cout << "=============================" << std::endl;
	}

private:
	void deleteLine(int indiceLine);
};

#endif // !GRID_GAME_DEF
