#ifndef EVENT_MANAGER_DEF
#define EVENT_MANAGER_DEF

#include <SFML/Graphics.hpp>
#include "ModelManager.h"
#include "SoundManager.h"

class EventManager {
public:
	ModelManager *model;
	SoundManager* son;

	EventManager();
	EventManager(ModelManager *model, SoundManager* son);
	void updateEvent(float delta, sf::RenderWindow& windows);
};

#endif // !EVENT_MANAGER_DEF