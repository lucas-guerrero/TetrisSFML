#ifndef LOAD_DATA_DEF
#define LOAD_DATA_DEF

#include "Tetromino.h"

class LoadData
{
private:
	char listLettre[7] = { 'Z', 'S', 'O', 'I', 'L', 'J', 'T'};

public:
	LoadData();
	Tetromino *getTetro(char tetromino);
	Tetromino* getTetro();
};

#endif // !LOAD_DATA_DEF

