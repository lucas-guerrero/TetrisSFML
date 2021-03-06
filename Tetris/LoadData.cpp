#include "LoadData.h"
#include <array>
#include <ctime>

LoadData::LoadData() {
	srand(time(NULL));
}

Tetromino *LoadData::getTetro(char tetromino)
{
	Tetromino* tetro = new Tetromino();
	switch (tetromino)
	{
		case 'S':
		{
			array<sf::Vector2i, 4> tetroZ1 = { sf::Vector2i(0, 0), sf::Vector2i(0, 1), sf::Vector2i(1, 1), sf::Vector2i(1, 2) };
			array<sf::Vector2i, 4> tetroZ2 = { sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(1,0), sf::Vector2i(2,0) };
			tetro->addTetromino(tetroZ2);
			tetro->addTetromino(tetroZ1);
			tetro->setColor(6);
			break;
		}
		case 'Z':
		{
			array<sf::Vector2i, 4> tetroS1 = { sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(0,1), sf::Vector2i(0,2) };
			array<sf::Vector2i, 4> tetroS2 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(2,1) };
			tetro->addTetromino(tetroS2);
			tetro->addTetromino(tetroS1);
			tetro->setColor(7);
			break;
		}
		case 'O':
		{
			array<sf::Vector2i, 4> tetroO1 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(0,1), sf::Vector2i(1,1) };
			tetro->addTetromino(tetroO1);
			tetro->setColor(3);
			break;
		}
		case 'I':
		{
			array<sf::Vector2i, 4> tetroI1 = { sf::Vector2i(0,0), sf::Vector2i(0,1), sf::Vector2i(0,2), sf::Vector2i(0,3) };
			array<sf::Vector2i, 4> tetroI2 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(2,0), sf::Vector2i(3,0) };
			tetro->addTetromino(tetroI2);
			tetro->addTetromino(tetroI1);
			tetro->setColor(2);
			break;
		}
		case 'L':
		{
			array<sf::Vector2i, 4> tetroL1 = { sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(1,2), sf::Vector2i(2,2) };
			array<sf::Vector2i, 4> tetroL2 = { sf::Vector2i(0,2), sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(2,1) };
			array<sf::Vector2i, 4> tetroL3 = { sf::Vector2i(0,0), sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(1,2) };
			array<sf::Vector2i, 4> tetroL4 = { sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(2,1), sf::Vector2i(2,0) };
			tetro->addTetromino(tetroL1);
			tetro->addTetromino(tetroL2);
			tetro->addTetromino(tetroL3);
			tetro->addTetromino(tetroL4);
			tetro->setColor(4);
			break;
		}
		case 'J':
		{
			array<sf::Vector2i, 4> tetroJ1 = { sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(1,2), sf::Vector2i(0,2) };
			array<sf::Vector2i, 4> tetroJ2 = { sf::Vector2i(0,0), sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(2,1) };
			array<sf::Vector2i, 4> tetroJ3 = { sf::Vector2i(2,0), sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(1,2) };
			array<sf::Vector2i, 4> tetroJ4 = { sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(2,1), sf::Vector2i(2,2) };
			tetro->addTetromino(tetroJ1);
			tetro->addTetromino(tetroJ2);
			tetro->addTetromino(tetroJ3);
			tetro->addTetromino(tetroJ4);
			tetro->setColor(1);
			break;
		}
		case 'T':
		{
			array<sf::Vector2i, 4> tetroT1 = { sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(1,0), sf::Vector2i(2,1) };
			array<sf::Vector2i, 4> tetroT2 = { sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(2,1), sf::Vector2i(1,2) };
			array<sf::Vector2i, 4> tetroT3 = { sf::Vector2i(0,1), sf::Vector2i(1,1), sf::Vector2i(1,2), sf::Vector2i(2,1) };
			array<sf::Vector2i, 4> tetroT4 = { sf::Vector2i(1,0), sf::Vector2i(1,1), sf::Vector2i(0,1), sf::Vector2i(1,2) };
			tetro->addTetromino(tetroT1);
			tetro->addTetromino(tetroT2);
			tetro->addTetromino(tetroT3);
			tetro->addTetromino(tetroT4);
			tetro->setColor(5);
			break;
		}
	}
	return tetro;
}

Tetromino* LoadData::getTetro()
{
	int lettre = rand() % 7;
	return getTetro(listLettre[lettre]);
}