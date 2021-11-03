#include "ViewManager.h"
#include <sstream>

ViewManager::ViewManager() : model(nullptr), texture(nullptr) { }
ViewManager::ViewManager(ModelManager *model, ResourcesManager* texture): model(model), texture(texture) { }

void ViewManager::updateView(float delta, sf::RenderWindow& windows) {

    windows.clear(sf::Color::Black);

    sf::Sprite fond(texture->textureFond);
    fond.setScale(sf::Vector2f(0.5, 0.5));
    windows.draw(fond);

    // Draw Extreminer grille
    sf::Vertex lineGridLeft[] = {
        sf::Vertex(sf::Vector2f(POSITION_GAME, 0)),
        sf::Vertex(sf::Vector2f(POSITION_GAME, SIZE_PIXELS * GAME_HEIGHT))
    };

    sf::Vertex lineGridRight[] = {
        sf::Vertex(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * GAME_WIDTH + 1, 0)),
        sf::Vertex(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * GAME_WIDTH + 1, SIZE_PIXELS * GAME_HEIGHT))
    };

    windows.draw(lineGridLeft, 2, sf::Lines);
    windows.draw(lineGridRight, 2, sf::Lines);


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

        // Draw Next tetro
        array<sf::Vector2i, 4> positionTetroNext = model->tetroSuivant->listTetrominos[0];
        sprite.scale(sf::Vector2f(0.5, 0.5));
        sprite.scale(sf::Vector2f(1.5, 1.5));
        for (int i = 0; i < 4; ++i) {
            sf::Vector2i block = positionTetroNext[i];

            sprite.setTexture(texture->texturesBlock[model->tetroSuivant->color - 1]);
            sprite.setPosition(sf::Vector2f(POSITION_INTERFACE_APRES + (SIZE_PIXELS / 1.5) * block.x + 40, POSITION_INTERFACE_Y + (SIZE_PIXELS / 1.5) * block.y));
            windows.draw(sprite);
        }

        // Draw Tetro Reserve
        if (model->tetroReserve != nullptr) {
            array<sf::Vector2i, 4> positionTetroReserve = model->tetroReserve->listTetrominos[0];
            for (int i = 0; i < 4; ++i) {
                sf::Vector2i block = positionTetroReserve[i];

                sprite.setTexture(texture->texturesBlock[model->tetroReserve->color - 1]);
                sprite.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT + (SIZE_PIXELS / 1.5) * block.x - 40, POSITION_INTERFACE_Y + (SIZE_PIXELS / 1.5) * block.y));
                windows.draw(sprite);
            }
        }
    }

    // Draw Espace tetromino: Reserve + Next
    sf::RectangleShape espaceTetro(sf::Vector2f((SIZE_PIXELS / 1.5) * 4 + 20, (SIZE_PIXELS / 1.5) * 4 + 20));
    espaceTetro.setFillColor(sf::Color::Transparent);
    espaceTetro.setOutlineThickness(1);

    espaceTetro.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 50, POSITION_INTERFACE_Y - 10));
    windows.draw(espaceTetro);

    espaceTetro.setPosition(sf::Vector2f(POSITION_INTERFACE_APRES + 30, POSITION_INTERFACE_Y - 10));
    windows.draw(espaceTetro);

    // Draw Power STOP
    sf::RectangleShape powerContour(sf::Vector2f( LONGUEUR_POWER, SIZE_PIXELS));
    powerContour.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 10, SIZE_PIXELS * (GAME_HEIGHT-3)));
    powerContour.setFillColor(sf::Color::Transparent);
    powerContour.setOutlineThickness(1);
    windows.draw(powerContour);

    sf::RectangleShape powerRec(sf::Vector2f( LONGUEUR_POWER * (model->power / 100), SIZE_PIXELS));
    powerRec.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 10, SIZE_PIXELS * (GAME_HEIGHT - 3)));
    windows.draw(powerRec);

    sf::RectangleShape flou(sf::Vector2f(RESOLUTION_X, RESOLUTION_Y));
    flou.setFillColor(sf::Color(0, 0, 0, 127));

    // Draw Interface

    sf::Text text;
    text.setFont(texture->fontClassique);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);

    stringstream ss;

    if (model->power >= POWER_MAX) {
        ss << "Ready";

        text.setString(ss.str());
        text.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT + 5, SIZE_PIXELS * (GAME_HEIGHT - 4)));
        windows.draw(text);
    }

    ss.str("");
    ss << "Power";

    text.setString(ss.str());
    text.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 100, SIZE_PIXELS* (GAME_HEIGHT - 3) + 5));
    windows.draw(text);

    ss.str("");
    ss << "Next";

    text.setString(ss.str());
    text.setPosition(sf::Vector2f(POSITION_INTERFACE_APRES + 45, 15));
    windows.draw(text);

    ss.str("");
    ss << "Reserve";

    text.setString(ss.str());
    text.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 50, 15));
    windows.draw(text);

    ss.str("");
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

    if (model->isPause) {
        windows.draw(flou);

        ss.str("");
        ss << "Press Escape to continue";

        text.setString(ss.str());
        text.setPosition(POSITION_CONTINUER);
        windows.draw(text);

        ss.str("");
        ss << "PAUSE";

        text.setString(ss.str());
        text.setCharacterSize(25);
        text.setPosition(POSITION_PAUSE);
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