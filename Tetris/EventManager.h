#ifndef EVENT_MANAGER_DEF
#define EVENT_MANAGER_DEF

#include <SFML/Graphics.hpp>
#include "ModelManager.h"

class EventManager {
public:
	ModelManager *model;

	EventManager();
	EventManager(ModelManager *model);
	void updateEvent(float delta, sf::RenderWindow& windows);
};

#endif // !EVENT_MANAGER_DEF