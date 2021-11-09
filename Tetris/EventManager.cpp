#include "EventManager.h"

EventManager::EventManager(): model(nullptr), son(nullptr) { }

EventManager::EventManager(ModelManager *model, SoundManager* son): model(model), son(son) { }

void EventManager::updateEvent(float delta, sf::RenderWindow& windows) {
    sf::Event event;
    while (windows.pollEvent(event))
    {
        if (event.type == sf::Event::Closed) windows.close();
        else if (event.type == sf::Event::KeyPressed) {
            if (model->status == ModelManager::Status::Game) {
                if (model->statusGame == ModelManager::Game::In) {
                    if (event.key.code == sf::Keyboard::Up) model->gameTetro.rotate();
                    else if (event.key.code == sf::Keyboard::Down) model->downPress();
                    else if (event.key.code == sf::Keyboard::Left) model->gameTetro.left();
                    else if (event.key.code == sf::Keyboard::Right) model->gameTetro.right();
                    else if (event.key.code == sf::Keyboard::Space) { son->tomber(); model->gameTetro.drop(); }
                    else if (event.key.code == sf::Keyboard::X) model->reserveTetro();
                    else if (event.key.code == sf::Keyboard::C) model->usePower();
                    else if (event.key.code == sf::Keyboard::M) son->mute();
                }
                else if (model->statusGame == ModelManager::Game::Over)
                    if (event.key.code == sf::Keyboard::Escape) model->status = ModelManager::Status::Menu;
                if (event.key.code == sf::Keyboard::R) model->restart();
                if (event.key.code == sf::Keyboard::Escape) model->pause();
                if (event.key.code == sf::Keyboard::F) model->modifyFpsHide();
            }
            else {
                if (model->statusMenu == ModelManager::Menu::Principal) {
                    if (event.key.code == sf::Keyboard::Enter) model->initGame();
                    else if (event.key.code == sf::Keyboard::H) model->statusMenu = ModelManager::Menu::Control;
                    else if (event.key.code == sf::Keyboard::Escape) windows.close();
                }
                else
                    if (event.key.code == sf::Keyboard::H) model->statusMenu = ModelManager::Menu::Principal;
                if (event.key.code == sf::Keyboard::F) model->modifyFpsHide();
            }
        }
        else if (event.type == sf::Event::KeyReleased) {
            if (model->status == ModelManager::Status::Game) {
                if (model->statusGame == ModelManager::Game::In) {
                    if (event.key.code == sf::Keyboard::Down) model->downRelease();
                }
            }
        }
    }
}