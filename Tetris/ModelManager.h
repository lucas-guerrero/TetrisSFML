#ifndef MODEL_MANAGER_DEF
#define MODEL_MANAGER_DEF

#include "LoadData.h"
#include "GridGame.h"
#include "TetrominoGame.h"

class ModelManager
{
public:
	GridGame grid = GridGame();
	LoadData data = LoadData();
	TetrominoGame gameTetro;
	Tetromino* tetro = nullptr;

	ModelManager();

	void initModel();
	void updateModel(float delta);

	void affich() {
		grid.affich();
	}
};

#endif // !MODEL_MANAGER_DEF

