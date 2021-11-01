#ifndef GAME_LOOP_DEF
#define GAME_LOOP_DEF

#include <SFML/Graphics.hpp>
#include "ViewManager.h"
#include "EventManager.h"
#include "ModelManager.h"
#include "TextureManager.h"

class GameLoop {
public:
	TextureManager textureManager;
	ViewManager viewManager;
	ModelManager modelManager;
	EventManager eventManager;
	sf::RenderWindow windows;

	void loadGame();
};

#endif // !GAME_LOOP_DEF