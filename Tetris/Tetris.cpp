#include <SFML/Graphics.hpp>
#include "GameLoop.h"
using namespace std;

int main()
{
    GameLoop *gameLoop = new GameLoop();
    gameLoop->loadGame();

    return 0;
}