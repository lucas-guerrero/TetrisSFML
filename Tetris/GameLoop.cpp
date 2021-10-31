#include <SFML/Graphics.hpp>
#include <time.h>
#include "VarUtils.h"
#include "GameLoop.h"

void GameLoop::loadGame() {    

    /*
    float delta = 1 / 60, timer = 0;
    clock_t clockBegin;
    clock_t clockEnd;
    */

    sf::RenderWindow windows(sf::VideoMode(GAME_WIDTH * SIZE_PIXELS, GAME_HEIGHT * SIZE_PIXELS), "Tetris SFML");

    viewManager = ViewManager(&modelManager);
    eventManager = EventManager(&modelManager);

    modelManager.initModel();
    
    while (windows.isOpen())
    { 
        eventManager.updateEvent(0, windows);
        modelManager.updateModel(0);
        viewManager.updateView(0, windows);
    }
}