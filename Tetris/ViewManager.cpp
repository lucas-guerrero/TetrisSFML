#include "ViewManager.h"

ViewManager::ViewManager() { }
ViewManager::ViewManager(ModelManager *model): model(model) { }

void ViewManager::updateView(float delta, sf::RenderWindow& windows) {

    windows.clear(sf::Color::Black);

    // Draw Grid

    sf::RectangleShape rec(sf::Vector2f(SIZE_PIXELS - 1, SIZE_PIXELS - 1));
    rec.setFillColor(sf::Color::Yellow);

    for (int i = 0; i < GAME_WIDTH; ++i) {
        for (int j = 0; j < GAME_HEIGHT; ++j) {
            if (model->grid.grid[i][j] == 1) {
                rec.setPosition(sf::Vector2f(SIZE_PIXELS * i, SIZE_PIXELS * j));
                windows.draw(rec);
            }
        }
    }

    // Draw Tetro Courant
    if (!model->grid.isEndGame()) {
        array<sf::Vector2i, 4> tetroActual = model->gameTetro.tetro->getTetroActual();

        rec.setFillColor(sf::Color::Red);

        for (int i = 0; i < 4; ++i)
        {
            sf::Vector2i block = tetroActual[i];

            rec.setPosition(sf::Vector2f(SIZE_PIXELS * block.x + model->gameTetro.dx, SIZE_PIXELS * block.y + model->gameTetro.dy));
            windows.draw(rec);
        }
    }

    windows.display();
}