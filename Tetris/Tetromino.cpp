#include "Tetromino.h"

void Tetromino::addTetromino(array<sf::Vector2i, 4> list)
{

	listTetrominos.push_back(list);
}

array<sf::Vector2i, 4> Tetromino::getTetroActual()
{
	return listTetrominos[rotation];
}

void Tetromino::rotate()
{
	rotation = (rotation + 1) % listTetrominos.size();
}

void Tetromino::deRotate()
{
	--rotation;
	if (rotation < 0) rotation = 0;
}