#include "ModelManager.h"
#include <cmath>

ModelManager::ModelManager() {
    gameTetro = TetrominoGame(&grid);
    status = Status::Menu;
    statusMenu = Menu::Principal;
    statusGame = Game::In;
}

ModelManager::~ModelManager() {
    delete tetro;
    delete tetroSuivant;
    delete tetroReserve;
}

void ModelManager::setSoundManager(SoundManager* son) {
    sound = son;
}

void ModelManager::initGame() {
    score = 0;
    nbLevel = 0;
    nbLine = 0;
    nbRow = 0;
    speed = SPEED_DEFAULT;
    power = 0;
    tetroReserve = nullptr;

    grid.initGrid();
    tetro = data.getTetro();
    tetroSuivant = data.getTetro();
    gameTetro.changeTetro(tetro);

    status = Status::Game;
    statusGame = Game::In;
    sound->play();
}

void ModelManager::restart() {
    delete tetro;
    delete tetroSuivant;
    delete tetroReserve;

    initGame();
}

void ModelManager::modifyFpsHide() {
    isFpsHide = !isFpsHide;
}

void ModelManager::updateModel(const double &freq) {
    fps = 1/freq;
    if (status == Status::Game && statusGame == Game::In) {
        if (powerUse)
            power -= POWER_USING * freq;
        else {
            gameTetro.down(speed * freq);

            if (power < POWER_MAX)
                power += POWER_AUGMENT * freq;
        }

        if (grid.isEndGame()) {
            sound->gameOver();
            statusGame = Game::Over;
        }

        int nbLigne = grid.checkLine();
        if (nbLigne > 0) 
            calculScore(nbLigne);

        if (powerUse && power <= 0) {
            power = 0;
            powerUse = false;
        }

        if (gameTetro.isStop) {
            gameTetro.transpose();

            isReserver = false;

            delete tetro;
            changeTetro();
        }
    }
}

void ModelManager::reserveTetro() {
    if (tetroReserve == nullptr) {
        isReserver = true;
        tetroReserve = tetro;
        changeTetro();
    }
    else {
        if (!isReserver) {
            isReserver = true;
            swap(tetro, tetroReserve);
            gameTetro.changeTetro(tetro);
        }
    }
}

void ModelManager::usePower() {
    if(power >= POWER_MAX && !powerUse)
        powerUse = true;
}

void ModelManager::pause() {
    if (statusGame != Game::Over) {
        sound->pause();
        if (statusGame == Game::Pause)
            statusGame = Game::In;
        else
            statusGame = Game::Pause;
    }
}

void ModelManager::changeTetro() {
    tetro = tetroSuivant;
    tetroSuivant = data.getTetro();
    gameTetro.changeTetro(tetro);
}

void ModelManager::calculScore(const int& nbLigne) {
    switch (nbLigne) {
    case 1:
        score += SCORE_ONE_LINE * (nbLevel + 1);
        break;
    case 2:
        score += SCORE_TWO_LINE * (nbLevel + 1);
        break;
    case 3:
        score += SCORE_THREE_LINE * (nbLevel + 1);
        break;
    case 4:
        score += SCORE_FOUR_LINE * (nbLevel + 1);
        break;
    }
    nbRow += nbLigne;
    nbLine += nbLigne;

    if (!powerUse) {
        power = power + nbLigne * POWER_LINE;
        if (power > POWER_MAX)
            power = POWER_MAX;
    }

    if (nbLine >= 10) {
        augmentLevel();
    }
}

void ModelManager::augmentLevel() {
    ++nbLevel;
    nbLine = nbRow % 10;
    speed += UP_SPEED;
}