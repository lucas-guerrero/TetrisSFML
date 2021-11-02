#ifndef MODEL_MANAGER_DEF
#define MODEL_MANAGER_DEF

#include "LoadData.h"
#include "GridGame.h"
#include "TetrominoGame.h"

class ModelManager
{
public:
	int score = 0;
	int nbLevel = 0;
	int nbLine = 0;
	int nbRow = 0;
	double fps = 0;
	double speed = SPEED_DEFAULT;

	bool isFpsHide = true;

	GridGame grid = GridGame();
	LoadData data = LoadData();
	TetrominoGame gameTetro;
	Tetromino* tetro = nullptr;

	ModelManager();

	void initModel();
	void updateModel(const double& freq);

	void modifyFpsHide();

	void restart();

private:
	void calculScore(const int &nbLignes);
	void augmentLevel();
};

#endif // !MODEL_MANAGER_DEF

