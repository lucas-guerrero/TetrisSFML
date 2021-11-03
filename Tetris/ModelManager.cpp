#include "ModelManager.h"
#include <cmath>

ModelManager::ModelManager() {
    gameTetro = TetrominoGame(&grid);
}

void ModelManager::initModel() {
    tetroSuivant = data.getTetro();
    tetro = data.getTetro();
    gameTetro.changeTetro(tetro);
}

void ModelManager::restart() {
    score = 0;
    nbLevel = 0;
    nbLine = 0;
    nbRow = 0;
    speed = SPEED_DEFAULT;
    power = 0;
    delete tetroReserve;
    tetroReserve = nullptr;

    grid.restart();

    initModel();
}

void ModelManager::modifyFpsHide() {
    isFpsHide = !isFpsHide;
}

void ModelManager::updateModel(const double &freq) {
    fps = 1/freq;
    if (!grid.isEndGame() && !isPause) {
        if (powerUse)
            power -= POWER_USING * freq;
        else
            gameTetro.down(speed * freq);
        int nbLigne = grid.checkLine();
        if (nbLigne > 0) {
            calculScore(nbLigne);
        }

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
    cout << "PAUSE" << endl;
    isPause = !isPause;
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
        if (power > 100)
            power = 100;
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