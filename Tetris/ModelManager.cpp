#include "ModelManager.h"

ModelManager::ModelManager() {
    gameTetro = TetrominoGame(&grid);
}

void ModelManager::initModel() {
    tetro = data.getTetro();
    gameTetro.changeTetro(tetro);
}

void ModelManager::updateModel(const double &freq) {
    fps = 1/freq;
    if (!grid.isEndGame()) {
        gameTetro.down(speed * freq);
        int nbLigne = grid.checkLine();
        if (nbLigne > 0) cout << nbLigne << endl;

        if (gameTetro.isStop) {
            gameTetro.transpose();

            delete tetro;

            tetro = data.getTetro();
            gameTetro.changeTetro(tetro);
        }
    }
    else
        cout << "End!!" << endl;
}