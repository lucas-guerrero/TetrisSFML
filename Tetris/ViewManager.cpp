#include "ViewManager.h"

ViewManager::ViewManager() : model(nullptr), texture(nullptr) { }
ViewManager::ViewManager(ModelManager *model, TextureManager* texture): model(model), texture(texture) { }

void ViewManager::updateView(float delta, sf::RenderWindow& windows) {

    windows.clear(sf::Color::Black);

    // Draw Grid
    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(0.5, 0.5));

    for (int i = 0; i < GAME_WIDTH; ++i) {
        for (int j = 0; j < GAME_HEIGHT; ++j) {
            if (model->grid.grid[i][j] > 0) {
                sprite.setTexture(texture->texturesBlock[model->grid.grid[i][j]-1]);
                sprite.setPosition(sf::Vector2f(SIZE_PIXELS * i, SIZE_PIXELS * j));
                windows.draw(sprite);
            }
        }
    }

    if (!model->grid.isEndGame()) {
        
        array<sf::Vector2i, 4> tetroActual = model->gameTetro.tetro->getTetroActual();

        // Draw Tetro Courant
        for (int i = 0; i < 4; ++i) {
            sf::Vector2i block = tetroActual[i];

            sprite.setTexture(texture->texturesBlock[model->gameTetro.tetro->color-1]);
            sprite.setPosition(sf::Vector2f(SIZE_PIXELS * block.x + model->gameTetro.dx, SIZE_PIXELS * block.y + model->gameTetro.dy));
            windows.draw(sprite);
        }

        // Draw Ghost Tetro Courant
        sf::Vector2<float> positionGhost = model->gameTetro.ghostBlock();
        for (int i = 0; i < 4; ++i) {
            sf::Vector2i block = tetroActual[i];

            sprite.setTexture(texture->texturesGhostBlock);
            sprite.setPosition(sf::Vector2f(SIZE_PIXELS * block.x + positionGhost.x, SIZE_PIXELS * block.y + positionGhost.y));
            windows.draw(sprite);
        }
    }

    windows.display();
}