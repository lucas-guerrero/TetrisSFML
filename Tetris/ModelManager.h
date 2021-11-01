#ifndef MODEL_MANAGER_DEF
#define MODEL_MANAGER_DEF

#include "LoadData.h"
#include "GridGame.h"
#include "TetrominoGame.h"

class ModelManager
{
public:
	double fps = 0;
	double speed = SPEED_DEFAULT;
	GridGame grid = GridGame();
	LoadData data = LoadData();
	TetrominoGame gameTetro;
	Tetromino* tetro = nullptr;

	ModelManager();

	void initModel();
	void updateModel(const double& freq);
};

#endif // !MODEL_MANAGER_DEF

