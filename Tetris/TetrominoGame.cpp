#include "TetrominoGame.h"
#include "VarUtils.h"

void TetrominoGame::changeTetro(Tetromino* tetro_)
{
	tetro = tetro_;
	isStop = false;
	dx = 0;
	dy = 0;
}

void TetrominoGame::rotate()
{
	float maxLast = dxMax();
	tetro->rotate();
	float maxAfter = dxMax();

	if (maxAfter < maxLast && dx > maxAfter) dx = maxAfter;
}

void TetrominoGame::left()
{
	if (dx > 0)
	{
		// si ca touche les tetromino deja placer
		dx -= SIZE_PIXELS;
	}
}

void TetrominoGame::right()
{
	if (dx < dxMax())
	{
		// si ca touche les tetromino deja placer
		dx += SIZE_PIXELS;
	}
}

void TetrominoGame::down(float vitesse)
{
	if (dy < dyMax())
	{
		dy += vitesse;
	}
	else isStop = true;
}

float TetrominoGame::dxMax()
{
	array<sf::Vector2i, 4> tmp = tetro->getTetroActual();
	int indiceMax = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (tmp[i].x > indiceMax) indiceMax = tmp[i].x;
	}
	return SIZE_PIXELS * ( GAME_WIDTH - indiceMax - 1);
}

float TetrominoGame::dyMax()
{
	array<sf::Vector2i, 4> tmp = tetro->getTetroActual();
	int indiceMax = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (tmp[i].y > indiceMax) indiceMax = tmp[i].y;
	}
	return SIZE_PIXELS * (GAME_HEIGHT - indiceMax - 1);
}