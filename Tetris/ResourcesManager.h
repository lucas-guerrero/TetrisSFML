#ifndef TEXTURE_MANAGER_DEF
#define TEXTURE_MANAGER_DEF
#include <SFML/Graphics.hpp>
#include <array>
#include "VarUtils.h"

class ResourcesManager {
public:
	std::array<sf::Texture, NB_TEXTURE_BLOCK> texturesBlock;
	sf::Texture texturesGhostBlock;
	sf::Texture textureFond;
	sf::Font fontClassique;

	ResourcesManager();
};

#endif // !TEXTURE_MANAGER_DEF