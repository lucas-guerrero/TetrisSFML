#include "ViewManager.h"
#include <sstream>

ViewManager::ViewManager() : model(nullptr), texture(nullptr) { }
ViewManager::ViewManager(ModelManager *model, ResourcesManager* texture): model(model), texture(texture) { }

void ViewManager::updateView(float delta, sf::RenderWindow& windows) {

    windows.clear(sf::Color::Black);

    sf::Text text;
    text.setFont(texture->fontClassique);
    text.setCharacterSize(15);
    text.setFillColor(sf::Color::White);

    if (model->status == ModelManager::Status::Menu)
        updateMenu(delta, windows, text);
    else {
        updateGame(delta, windows);

        sf::RectangleShape flou(sf::Vector2f(RESOLUTION_X, RESOLUTION_Y));
        flou.setFillColor(sf::Color(0, 0, 0, 127));

        // Draw Interface
        affichUI(delta, windows, text);

        if (model->statusGame == ModelManager::Game::Over) {
            updateOver(delta, windows, text, flou);
        }
        else if (model->statusGame == ModelManager::Game::Pause) {
            updatePause(delta, windows, text, flou);
        }
    }

    stringstream ss;

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

void ViewManager::updateMenu(float delta, sf::RenderWindow& windows, sf::Text text) {
    text.setString("Tetris");
    text.setPosition(sf::Vector2f((RESOLUTION_X)/2 - 75, POSITION_TITRE_Y));
    text.setCharacterSize(25);
    windows.draw(text);

    if (model->statusMenu == ModelManager::Menu::Control) {
        text.setString("Control");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 65, POSITION_SOUS_TITRE_Y));
        text.setCharacterSize(20);
        windows.draw(text);

        text.setString("Press H to return");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 175, (RESOLUTION_Y) / 2 + 250));
        windows.draw(text);

        text.setString("Move: Left / Right");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2 - 100));
        text.setCharacterSize(15);
        windows.draw(text);

        text.setString("Rotate: Up");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2 - 50));
        windows.draw(text);

        text.setString("Drop: Down");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2));
        windows.draw(text);

        text.setString("Drop Hard: Space");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2 + 50));
        windows.draw(text);

        text.setString("Reserve: X");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2 + 100));
        windows.draw(text);

        text.setString("Power: C");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2 + 150));
        windows.draw(text);
    }
    else {
        text.setString("Press Enter to Play");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 135, (RESOLUTION_Y) / 2 - 100));
        text.setCharacterSize(15);
        windows.draw(text);

        text.setString("Press H to Control");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 125, (RESOLUTION_Y) / 2));
        windows.draw(text);

        text.setString("Press Escape to Quit");
        text.setPosition(sf::Vector2f((RESOLUTION_X) / 2 - 140, (RESOLUTION_Y) / 2 + 100));
        windows.draw(text);
    }
}

void ViewManager::affichUI(float delta, sf::RenderWindow& windows, sf::Text text) {
    stringstream ss;

    // Draw Espace tetromino: Reserve + Next
    sf::RectangleShape espaceTetro(sf::Vector2f((SIZE_PIXELS / 1.5) * 4 + 20, (SIZE_PIXELS / 1.5) * 4 + 20));
    espaceTetro.setFillColor(sf::Color::Transparent);
    espaceTetro.setOutlineThickness(1);

    espaceTetro.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 50, POSITION_INTERFACE_Y - 10));
    windows.draw(espaceTetro);

    espaceTetro.setPosition(sf::Vector2f(POSITION_INTERFACE_APRES + 30, POSITION_INTERFACE_Y - 10));
    windows.draw(espaceTetro);

    // Draw Power STOP
    sf::RectangleShape powerContour(sf::Vector2f(LONGUEUR_POWER, SIZE_PIXELS));
    powerContour.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 10, SIZE_PIXELS * (GAME_HEIGHT - 3)));
    powerContour.setFillColor(sf::Color::Transparent);
    powerContour.setOutlineThickness(1);
    windows.draw(powerContour);

    sf::RectangleShape powerRec(sf::Vector2f(LONGUEUR_POWER * (model->power / 100), SIZE_PIXELS));
    powerRec.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 10, SIZE_PIXELS * (GAME_HEIGHT - 3)));
    windows.draw(powerRec);

    if (model->power >= POWER_MAX) {
        text.setString("Press C");
        text.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 10, SIZE_PIXELS * (GAME_HEIGHT - 4)));
        windows.draw(text);
    }

    text.setString("Power");
    text.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT - 100, SIZE_PIXELS * (GAME_HEIGHT - 3) + 5));
    windows.draw(text);

    text.setString("Next");
    text.setPosition(sf::Vector2f(POSITION_INTERFACE_APRES + 45, 15));
    windows.draw(text);

    text.setString("Reserve");
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
}

void ViewManager::updateGame(float delta, sf::RenderWindow& windows) {
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
                sprite.setTexture(texture->texturesBlock[model->grid.grid[i][j] - 1]);
                sprite.setPosition(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * i, SIZE_PIXELS * j));
                windows.draw(sprite);
            }
        }
    }

    array<sf::Vector2i, 4> tetroActual = model->gameTetro.tetro->getTetroActual();

    // Draw Tetro Courant
    for (int i = 0; i < 4; ++i) {
        sf::Vector2i block = tetroActual[i];

        sprite.setTexture(texture->texturesBlock[model->gameTetro.tetro->color - 1]);
        sprite.setPosition(sf::Vector2f(POSITION_GAME + SIZE_PIXELS * block.x + model->gameTetro.dx, SIZE_PIXELS * block.y + model->gameTetro.dy));
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
    sprite.scale(sf::Vector2f(0.75, 0.75));
    for (int i = 0; i < 4; ++i) {
        sf::Vector2i block = positionTetroNext[i];

        sprite.setTexture(texture->texturesBlock[model->tetroSuivant->color - 1]);
        sprite.setPosition(sf::Vector2f(POSITION_INTERFACE_APRES + (SIZE_PIXELS / 1.25) * block.x + 32.5, POSITION_INTERFACE_Y + (SIZE_PIXELS / 1.25) * block.y));
        windows.draw(sprite);
    }

    // Draw Tetro Reserve
    if (model->tetroReserve != nullptr) {
        array<sf::Vector2i, 4> positionTetroReserve = model->tetroReserve->listTetrominos[0];
        for (int i = 0; i < 4; ++i) {
            sf::Vector2i block = positionTetroReserve[i];

            sprite.setTexture(texture->texturesBlock[model->tetroReserve->color - 1]);
            sprite.setPosition(sf::Vector2f(POSITION_INTERFACE_AVANT + (SIZE_PIXELS / 1.25) * block.x - 47.5, POSITION_INTERFACE_Y + (SIZE_PIXELS / 1.25) * block.y));
            windows.draw(sprite);
        }
    }
}

void ViewManager::updateOver(float delta, sf::RenderWindow& windows, sf::Text& text, sf::RectangleShape flou) {
    windows.draw(flou);

    text.setString("Press R to Restart");
    text.setPosition(POSITION_RESTART);
    windows.draw(text);

    text.setString("Press Escape to Menu");
    text.setPosition(POSITION_ESCAPE_MENU);
    windows.draw(text);

    text.setString("GAME OVER");
    text.setCharacterSize(25);
    text.setPosition(POSITION_GAMEOVER);
    windows.draw(text);
}

void ViewManager::updatePause(float delta, sf::RenderWindow& windows, sf::Text& text, sf::RectangleShape flou) {
    windows.draw(flou);

    text.setString("Press Escape to Continue");
    text.setPosition(POSITION_CONTINUER);
    windows.draw(text);

    text.setString("PAUSE");
    text.setCharacterSize(25);
    text.setPosition(POSITION_PAUSE);
    windows.draw(text);
}