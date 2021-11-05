#ifndef GAME_LOOP_DEF
#define GAME_LOOP_DEF

#include <SFML/Graphics.hpp>
#include "ViewManager.h"
#include "EventManager.h"
#include "ModelManager.h"
#include "ResourcesManager.h"
#include "SoundManager.h"

class GameLoop {
public:
	ResourcesManager textureManager;
	ViewManager viewManager;
	ModelManager modelManager;
	EventManager eventManager;
	SoundManager soundManager;
	sf::RenderWindow windows;

	void loadGame();
};

#endif // !GAME_LOOP_DEF