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
	void updateMenu(float delta, sf::RenderWindow& windows, sf::Text text);
	void updateGame(float delta, sf::RenderWindow& windows);
	void affichUI(float delta, sf::RenderWindow& windows, sf::Text text);
	void updateOver(float delta, sf::RenderWindow& windows, sf::Text& text, sf::RectangleShape flou);
	void updatePause(float delta, sf::RenderWindow& windows, sf::Text& text, sf::RectangleShape flou);
};

#endif // !VIEW_MANAGER_DEF

