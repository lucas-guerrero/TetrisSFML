#include "TetrominoGame.h"
#include "VarUtils.h"

TetrominoGame::TetrominoGame() {
	tetro = nullptr;
	isStop = false;
	dx = (GAME_WIDTH * SIZE_PIXELS) / 2 - SIZE_PIXELS;
	dy = 0;
	gridGame = nullptr;
}

TetrominoGame::TetrominoGame(GridGame *grid): gridGame(grid) {
	tetro = nullptr;
	isStop = false;
	dx = (GAME_WIDTH * SIZE_PIXELS) / 2 - SIZE_PIXELS;
	dy = 0;
}

void TetrominoGame::changeTetro(Tetromino* tetro_) {
	tetro = tetro_;
	isStop = false;
	dx = (GAME_WIDTH * SIZE_PIXELS)/2 - SIZE_PIXELS;
	dy = 0;
}

void TetrominoGame::rotate() {
	float maxLast = dxMax();
	float minLast = dxMin();
	tetro->rotate();
	float maxAfter = dxMax();
	float minAfter = dxMin();
	if (dx > maxAfter)
		dx = maxAfter;
	else if(dx <= minAfter)
		dx = 0;
	isEmbedded();
}

void TetrominoGame::left() {
	if (!isCollision(0))
		dx -= SIZE_PIXELS;
}

void TetrominoGame::right() {
	if (!isCollision(2))
		dx += SIZE_PIXELS;
}

void TetrominoGame::down(double vitesse) {
	if (!isCollision(1))
		dy += vitesse;
	else
		isStop = true;
}

void TetrominoGame::transpose() {
	int indiceX = dx / SIZE_PIXELS;
	int indiceY = dy / SIZE_PIXELS;

	array<sf::Vector2i, 4> tetroTmp = tetro->getTetroActual();

	for (int i = 0; i < 4; ++i) {
		gridGame->grid[indiceX + tetroTmp[i].x][indiceY + tetroTmp[i].y] = 1;
	}
}

float TetrominoGame::dxMax() {
	array<sf::Vector2i, 4> tmp = tetro->getTetroActual();
	int indiceMax = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (tmp[i].x > indiceMax) indiceMax = tmp[i].x;
	}
	return SIZE_PIXELS * ( GAME_WIDTH - indiceMax - 1);
}

float TetrominoGame::dxMin() {
	array<sf::Vector2i, 4> tmp = tetro->getTetroActual();
	int indiceMin = 4;
	for (int i = 0; i < 4; ++i)
	{
		if (tmp[i].x < indiceMin) indiceMin = tmp[i].x;
	}
	return SIZE_PIXELS * (indiceMin-1);
}

void TetrominoGame::isEmbedded() {
	int indiceX = dx / SIZE_PIXELS;
	int indiceY = dy / SIZE_PIXELS;
	array<sf::Vector2i, 4> tmp = tetro->getTetroActual();
	for (int i = 0; i < 4; ++i)
	{
		if (!gridGame->isEmbedded(indiceX + tmp[i].x, indiceY + tmp[i].y))
		{
			tetro->deRotate();
			return;
		}
	}
}

bool TetrominoGame::isCollision(int idCollision) {
	int indiceX = dx / SIZE_PIXELS;
	int indiceY = dy / SIZE_PIXELS;
	array<sf::Vector2i, 4> tmp = tetro->getTetroActual();
	for (int i = 0; i < 4; ++i)
	{
		if (gridGame->checkNeighbor(indiceX + tmp[i].x, indiceY + tmp[i].y)[idCollision]) 
			return true;
	}
	return false;
}