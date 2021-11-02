#include "ModelManager.h"
#include <cmath>

ModelManager::ModelManager() {
    gameTetro = TetrominoGame(&grid);
}

void ModelManager::initModel() {
    tetro = data.getTetro();
    gameTetro.changeTetro(tetro);
}

void ModelManager::restart() {
    score = 0;
    nbLevel = 0;
    nbLine = 0;
    nbRow = 0;
    speed = SPEED_DEFAULT;

    grid.restart();

    initModel();
}

void ModelManager::modifyFpsHide() {
    isFpsHide = !isFpsHide;
}

void ModelManager::updateModel(const double &freq) {
    fps = 1/freq;
    if (!grid.isEndGame()) {
        gameTetro.down(speed * freq);
        int nbLigne = grid.checkLine();
        if (nbLigne > 0) {
            calculScore(nbLigne);
        }

        if (gameTetro.isStop) {
            gameTetro.transpose();

            delete tetro;

            tetro = data.getTetro();
            gameTetro.changeTetro(tetro);
        }
    }
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
    if (nbLine >= 10) {
        augmentLevel();
    }
}

void ModelManager::augmentLevel() {
    ++nbLevel;
    nbLine = nbRow % 10;
    speed += 20;
}