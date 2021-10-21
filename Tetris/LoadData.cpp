#include "LoadData.h"
#include <array>

Tetromino *LoadData::getTetro(char tetromino)
{
	Tetromino* tetro = new Tetromino();
	switch (tetromino)
	{
		case 'Z':
		{
			array<sf::Vector2i, 4> tetroZ1 = { sf::Vector2i(0, 0), sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(1, 2) };
			array<sf::Vector2i, 4> tetroZ2 = { sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(1,0), sf::Vector2i(2,0) };
			tetro->addTetromino(tetroZ1);
			tetro->addTetromino(tetroZ2);
			break;
		}
		case 'S':
		{
			array<sf::Vector2i, 4> tetroS1 = { sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(0,1), sf::Vector2i(0,2) };
			array<sf::Vector2i, 4> tetroS2 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(2,1) };
			tetro->addTetromino(tetroS1);
			tetro->addTetromino(tetroS2);
			break;
		}
		case 'O':
		{
			array<sf::Vector2i, 4> tetroO1 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(0,1), sf::Vector2i(1,1) };
			tetro->addTetromino(tetroO1);
			break;
		}
		case 'I':
		{
			array<sf::Vector2i, 4> tetroI1 = { sf::Vector2i(0,0), sf::Vector2i(0,1), sf::Vector2i(0,2), sf::Vector2i(0,3) };
			array<sf::Vector2i, 4> tetroI2 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(2,0), sf::Vector2i(3,0) };
			tetro->addTetromino(tetroI1);
			tetro->addTetromino(tetroI2);
			break;
		}
		case 'L':
		{

		}
		case 'J':
		{

		}
		case 'T':
		{

		}
	}
	return tetro;
}

Tetromino* LoadData::getTetro()
{
	int lettre = rand() % 4;
	return getTetro(listLettre[lettre]);
}