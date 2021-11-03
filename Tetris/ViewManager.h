#ifndef VIEW_MANAGER_DEF
#define VIEW_MANAGER_DEF

#include <SFML/Graphics.hpp>
#include "ModelManager.h"
#include "ResourcesManager.h"

class ViewManager
{
public:
	ModelManager* model;
	ResourcesManager* texture;


	ViewManager();
	ViewManager(ModelManager *model, ResourcesManager* texture);

	void updateView(float delta, sf::RenderWindow &windows);
};

#endif // !VIEW_MANAGER_DEF

