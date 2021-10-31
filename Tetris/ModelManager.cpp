#include "ModelManager.h"

ModelManager::ModelManager() {
    gameTetro = TetrominoGame(&grid);
}

void ModelManager::initModel() {
    tetro = data.getTetro();
    gameTetro.changeTetro(tetro);
}

void ModelManager::updateModel(float delta) {

    if (!grid.isEndGame()) {
        gameTetro.down(0.05); // faire un truc avec delta
        int nbLigne = grid.checkLine();
        if (nbLigne > 0) cout << nbLigne << endl;

        if (gameTetro.isStop) {
            gameTetro.transpose();

            delete tetro;

            tetro = data.getTetro();
            gameTetro.changeTetro(tetro);
        }
    }
}