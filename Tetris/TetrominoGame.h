#ifndef TETROMINO_GAME_DEF
#define TETROMINO_GAME_DEF
#include "Tetromino.h"

class TetrominoGame
{
public:
	Tetromino* tetro;
	float dx, dy;
	bool isStop;

	void changeTetro(Tetromino* tetro_);
	void rotate();
	void left();
	void right();
	void down(float vitesse);

private:
	float dxMax();
	float dyMax();
};

#endif // !TETROMINO_GAME_DEF