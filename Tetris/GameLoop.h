#include "LoadData.h"
#include "GridGame.h"

class GameLoop
{
public:
	GridGame grid;
	LoadData data;

	void initGame();
	void loadGame();
};