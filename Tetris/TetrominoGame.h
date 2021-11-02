#ifndef TETROMINO_GAME_DEF
#define TETROMINO_GAME_DEF
#include "Tetromino.h"
#include "GridGame.h"

class TetrominoGame {
public:
	GridGame *gridGame;
	Tetromino *tetro;
	float dx, dy;
	float timeCollision;
	bool isStop;

	TetrominoGame();
	TetrominoGame(GridGame *grid);

	void changeTetro(Tetromino* tetro_);
	void rotate();
	void left();
	void right();
	void down(double vitesse);
	void drop();

	sf::Vector2<float> ghostBlock();

	void transpose();

private:
	float dxMax();
	float dxMin();
	float dyMax();
	bool isEmbedded();
	bool isCollisionY(float y);
	bool isCollision(int idCollision); // idCollision = 0 => gauche; 1 => bas; 2 => droite
};

#endif // !TETROMINO_GAME_DEF