#ifndef DATA_TETROMINO_DEF
#define DATA_TETROMINO_DEF

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <array>

using namespace std;

class Tetromino
{
public:
	vector<array<sf::Vector2i, 4>> listTetrominos; // vecteur d'un tableau representant un tetramino avec ces points locals. Ce vecteur utilise toutes les rotations du tetraminos mére
	int rotation = 0;

	void addTetromino(array<sf::Vector2i, 4> tetro);
	array<sf::Vector2i, 4> getTetroActual();
	void rotate();
	void deRotate();
};

#endif // !DATA_TETROMINO_DEF