#ifndef MODEL_MANAGER_DEF
#define MODEL_MANAGER_DEF

#include "LoadData.h"
#include "GridGame.h"
#include "TetrominoGame.h"
#include "SoundManager.h"

class ModelManager
{
public:
	enum class Menu { Principal, Control };
	enum class Game { In, Pause, Over };
	enum class Status { Menu, Game };

	int score = 0;
	int nbLevel = 0;
	int nbLine = 0;
	int nbRow = 0;
	double fps = 0;
	double speed = SPEED_DEFAULT;

	bool isFpsHide = true;
	bool isReserver = false;
	bool powerUse = false;
	float power = 0;

	Status status;
	Menu statusMenu;
	Game statusGame;

	GridGame grid = GridGame();
	LoadData data = LoadData();
	TetrominoGame gameTetro;
	Tetromino* tetro = nullptr;
	Tetromino* tetroSuivant = nullptr;
	Tetromino* tetroReserve = nullptr;
	SoundManager* sound = nullptr;

	ModelManager();
	~ModelManager();

	void setSoundManager(SoundManager* sound);

	void initGame();
	void updateModel(const double& freq);
	void reserveTetro();
	void usePower();
	void pause();

	void modifyFpsHide();

	void restart();

private:
	void calculScore(const int &nbLignes);
	void augmentLevel();
	void changeTetro();
};

#endif // !MODEL_MANAGER_DEF

