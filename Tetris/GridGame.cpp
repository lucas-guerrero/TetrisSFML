#include "GridGame.h"
#include <vector>
#include <iostream>

void GridGame::initGrid() {
	for (int i = 0; i < GAME_WIDTH; ++i)
		for (int j = 0; j < GAME_HEIGHT; ++j)
			grid[i][j] = 0;
}

int GridGame::checkLine() {
	int nbLigneDelete = 0;
	int j = GAME_HEIGHT - 1;
	while (j >= 0) {
		int i = 0;
		while (grid[i][j] > 0 && i < GAME_WIDTH)
			++i;
		if (i >= GAME_WIDTH) {
			deleteLine(j);
			++nbLigneDelete;
		}
		else
			--j;
	}
	return nbLigneDelete;
}

bool* GridGame::checkNeighbor(int indexX, int indexY) {
	bool list[3] = {false, false, false};
	if (indexX < 1 || grid[indexX - 1][indexY])
		list[0] = true;

	if (indexY >= GAME_HEIGHT-1 || grid[indexX][indexY + 1])
		list[1] = true;

	if (indexX >= GAME_WIDTH-1 || grid[indexX + 1][indexY])
		list[2] = true;

	return list;
}

bool GridGame::isEmbedded(int indexX, int indexY) {
	if (indexY > GAME_HEIGHT - 1 || indexY < 0)
		return false;
	else if (indexX > GAME_WIDTH - 1 || indexX < 0)
		return false;
	return grid[indexX][indexY] < 1;
}


bool GridGame::isEndGame() {
	for (int i = 0; i < GAME_WIDTH; ++i)
		if (grid[i][0] > 0)
			return true;
	return false;
}

void GridGame::deleteLine(int indiceLine) {
	for (int j = indiceLine; j >= 0; --j)
	{
		for (int i = 0; i < GAME_WIDTH; ++i)
			if (j == 0)
				grid[i][j] = 0;
			else
				grid[i][j] = grid[i][j - 1];
	}
}

