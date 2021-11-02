#include "ViewManager.h"
#include <sstream>

ViewManager::ViewManager() : model(nullptr), texture(nullptr) { }
ViewManager::ViewManager(ModelManager *model, TextureManager* texture): model(model), texture(texture) { }

void ViewManager::updateView(float delta, sf::RenderWindow& windows) {

    windows.clear(sf::Color::Black);

    sf::Vertex lineLeft[] =
    {
        sf::Vertex(sf::Vector2f(POSITION_GAME, 0)),
        sf::Vertex(sf::Vector2f(POSITION_GAME, SIZE_PIXELS * GAME_HEIGHT))
    };

    sf::Vertex lineRight[] =
    {
        sf::Vertex(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * GAME_WIDTH + 1, 0)),
        sf::Vertex(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * GAME_WIDTH + 1, SIZE_PIXELS * GAME_HEIGHT))
    };

    windows.draw(lineLeft, 2, sf::Lines);
    windows.draw(lineRight, 2, sf::Lines);

    // Draw Grid
    sf::Sprite sprite;
    sprite.setScale(sf::Vector2f(0.5, 0.5));

    for (int i = 0; i < GAME_WIDTH; ++i) {
        for (int j = 0; j < GAME_HEIGHT; ++j) {
            if (model->grid.grid[i][j] > 0) {
                sprite.setTexture(texture->texturesBlock[model->grid.grid[i][j]-1]);
                sprite.setPosition(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * i, SIZE_PIXELS * j));
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
            sprite.setPosition(sf::Vector2f(POSITION_GAME +  SIZE_PIXELS * block.x + model->gameTetro.dx, SIZE_PIXELS * block.y + model->gameTetro.dy));
            windows.draw(sprite);
        }

        // Draw Ghost Tetro Courant
        sf::Vector2<float> positionGhost = model->gameTetro.ghostBlock();
        for (int i = 0; i < 4; ++i) {
            sf::Vector2i block = tetroActual[i];

            sprite.setTexture(texture->texturesGhostBlock);
            sprite.setPosition(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * block.x + positionGhost.x, SIZE_PIXELS * block.y + positionGhost.y));
            windows.draw(sprite);
        }
    }

    sf::RectangleShape flou(sf::Vector2f(RESOLUTION_X, RESOLUTION_Y));
    flou.setFillColor(sf::Color(0, 0, 0, 127));

    // Draw Interface

    sf::Text text;
    text.setFont(texture->fontClassique);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);

    stringstream ss;
    ss << "Levels: " << model->nbLevel;

    text.setString(ss.str());
    text.setPosition(POSITION_LEVEL);
    windows.draw(text);

    ss.str("");
    ss << "Lines: " << model->nbRow;

    text.setString(ss.str());
    text.setPosition(POSITION_LINE);
    windows.draw(text);

    ss.str("");
    ss << "Score: " << model->score;

    text.setString(ss.str());
    text.setPosition(POSITION_SCORE);
    windows.draw(text);

    if (model->grid.isEndGame()) {
        windows.draw(flou);

        ss.str("");
        ss << "Press R to restart";

        text.setString(ss.str());
        text.setPosition(POSITION_RESTART);
        windows.draw(text);

        ss.str("");
        ss << "GAME OVER";

        text.setString(ss.str());
        text.setCharacterSize(25);
        text.setPosition(POSITION_GAMEOVER);
        windows.draw(text);
    }

    if (!model->isFpsHide) {
        ss.str("");
        ss << "FPS: " << round(model->fps);

        text.setString(ss.str());
        text.setPosition(sf::Vector2f(10, GAME_HEIGHT * (SIZE_PIXELS - 1)));
        text.setCharacterSize(10);
        windows.draw(text);
    }

    windows.display();
}