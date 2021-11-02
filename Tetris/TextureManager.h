#ifndef TEXTURE_MANAGER_DEF
#define TEXTURE_MANAGER_DEF
#include <SFML/Graphics.hpp>
#include <array>
#include "VarUtils.h"

class TextureManager {
public:
	std::array<sf::Texture, NB_TEXTURE_BLOCK> texturesBlock;
	sf::Texture texturesGhostBlock;
	sf::Texture textureBr;
	sf::Font fontClassique;

	TextureManager();
};

#endif // !TEXTURE_MANAGER_DEF