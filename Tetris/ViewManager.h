#ifndef VIEW_MANAGER_DEF
#define VIEW_MANAGER_DEF

#include <SFML/Graphics.hpp>
#include "ModelManager.h"

class ViewManager
{
public:
	ModelManager *model;

	ViewManager();
	ViewManager(ModelManager *model);

	void updateView(float delta, sf::RenderWindow &windows);
};

#endif // !VIEW_MANAGER_DEF

