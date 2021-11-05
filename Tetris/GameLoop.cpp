#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "VarUtils.h"
#include "GameLoop.h"

void GameLoop::loadGame() {

    sf::RenderWindow windows(sf::VideoMode( RESOLUTION_X, RESOLUTION_Y), "Tetris SFML");

    modelManager.setSoundManager(&soundManager);

    viewManager = ViewManager(&modelManager, &textureManager);
    eventManager = EventManager(&modelManager, &soundManager);

    modelManager.initModel();

    sf::Time time;
    sf::Clock clock;
    float dt = clock.getElapsedTime().asSeconds();

    windows.setFramerateLimit(LIMITE_FPS);
    while (windows.isOpen()) {

        time = clock.restart();

        eventManager.updateEvent(dt, windows);
        modelManager.updateModel(dt);
        viewManager.updateView(dt, windows);

        dt = time.asSeconds();
    }
}