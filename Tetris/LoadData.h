#ifndef LOAD_DATA_DEF
#define LOAD_DATA_DEF

#include "Tetromino.h"

class LoadData
{
private:
	char listLettre[4] = { 'Z', 'S', 'O', 'I'};

public:

	Tetromino *getTetro(char tetromino);
	Tetromino* getTetro();
};

#endif // !LOAD_DATA_DEF

