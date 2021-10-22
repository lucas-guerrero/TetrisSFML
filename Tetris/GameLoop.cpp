#include <SFML/Graphics.hpp>
#include "VarUtils.h"
#include "GameLoop.h"
#include "TetrominoGame.h"


void GameLoop::initGame()
{
    
}

void GameLoop::loadGame()
{    
    sf::RenderWindow window(sf::VideoMode(GAME_WIDTH * SIZE_PIXELS, GAME_HEIGHT * SIZE_PIXELS), "Tetris SFML");

    Tetromino* tetro = data.getTetro();

    TetrominoGame gameTetro = TetrominoGame(&grid);
    gameTetro.changeTetro(tetro);


    array<sf::Vector2i, 4> t = gameTetro.tetro->getTetroActual();
    for (int i = 0; i < 4; ++i)
    {
        sf::Vector2i block = t[i];
        cout << "(" << block.x << ", " << block.y << ")" << endl;
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (!gameTetro.isStop)
                {
                    if (event.key.code == sf::Keyboard::Up) gameTetro.rotate();
                    else if (event.key.code == sf::Keyboard::Left) gameTetro.left();
                    else if (event.key.code == sf::Keyboard::Right) gameTetro.right();
                }
        }

        if (!grid.isEndGame())
        {
            gameTetro.down(0.05);
            int nbLigne = grid.checkLine();
            if (nbLigne > 0) cout << nbLigne << endl;

            if (gameTetro.isStop)
            {
                gameTetro.transpose();

                delete tetro;

                tetro = data.getTetro();
                gameTetro.changeTetro(tetro);
            }
        }
        else
            cout << "END of GAME !!!" << endl;

        // Draw Grid

        sf::RectangleShape rec(sf::Vector2f(SIZE_PIXELS - 1, SIZE_PIXELS - 1));
        rec.setFillColor(sf::Color::Yellow);

        for (int i = 0; i < GAME_WIDTH; ++i)
        {
            for (int j = 0; j < GAME_HEIGHT; ++j)
            {
                if (grid.grid[i][j] == 1)
                {
                    rec.setPosition(sf::Vector2f(SIZE_PIXELS * i, SIZE_PIXELS * j));
                    window.draw(rec);
                }
            }
        }

        // Draw Tetro Courant

        array<sf::Vector2i, 4> tetroActual = gameTetro.tetro->getTetroActual();

        rec.setFillColor(sf::Color::Red);

        for (int i = 0; i < 4; ++i)
        {
            sf::Vector2i block = tetroActual[i];

            rec.setPosition(sf::Vector2f(SIZE_PIXELS * block.x + gameTetro.dx, SIZE_PIXELS * block.y + gameTetro.dy));
            window.draw(rec);
        }

        /*
        for (int i = 0; i < GAME_WIDTH; ++i)
        {
            for (int j = 0; j < GAME_HEIGHT; ++j)
            {
                rec.setPosition(sf::Vector2f(SIZE_PIXELS * i, SIZE_PIXELS * j));
                window.draw(rec);
            }
        }
        */

        window.display();
        window.clear(sf::Color::Black);
    }

    delete tetro;
}