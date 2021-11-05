#include "EventManager.h"

EventManager::EventManager(): model(nullptr), son(nullptr) { }

EventManager::EventManager(ModelManager *model, SoundManager* son): model(model), son(son) { }

void EventManager::updateEvent(float delta, sf::RenderWindow& windows) {
    sf::Event event;
    while (windows.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) windows.close();
        else if (event.type == sf::Event::KeyPressed)
            if (!model->gameTetro.isStop && !model->grid.isEndGame()) {
                if (!model->isPause) {
                    if (event.key.code == sf::Keyboard::Up) model->gameTetro.rotate();
                    else if (event.key.code == sf::Keyboard::Down) model->gameTetro.down(25);
                    else if (event.key.code == sf::Keyboard::Left) model->gameTetro.left();
                    else if (event.key.code == sf::Keyboard::Right) model->gameTetro.right();
                    else if (event.key.code == sf::Keyboard::Space) { son->tomber(); model->gameTetro.drop(); }
                    else if (event.key.code == sf::Keyboard::X) model->reserveTetro();
                    else if (event.key.code == sf::Keyboard::C) model->usePower();

                    else if (event.key.code == sf::Keyboard::F) model->modifyFpsHide();
                }
                if (event.key.code == sf::Keyboard::Escape) { son->pause(); model->pause(); }
            }
            else
                if (event.key.code == sf::Keyboard::R) model->restart();
    }
}