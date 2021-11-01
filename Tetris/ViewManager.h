#ifndef VIEW_MANAGER_DEF
#define VIEW_MANAGER_DEF

#include <SFML/Graphics.hpp>
#include "ModelManager.h"
#include "TextureManager.h"

class ViewManager
{
public:
	ModelManager* model;
	TextureManager* texture;


	ViewManager();
	ViewManager(ModelManager *model, TextureManager* texture);

	void updateView(float delta, sf::RenderWindow &windows);
};

#endif // !VIEW_MANAGER_DEF

