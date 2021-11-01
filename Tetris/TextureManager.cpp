#include "TextureManager.h"
#include <sstream>

using namespace std;

TextureManager::TextureManager() {
	texturesBlock = array<sf::Texture, NB_TEXTURE_BLOCK>();

	stringstream ss;

	for (int i = 0; i < NB_TEXTURE_BLOCK; ++i) {
		ss << "resources/tetris" << i << ".png";
		if (!texturesBlock[i].loadFromFile(ss.str()))
			throw runtime_error("Load Texture Block");
		ss.str(string());
		texturesBlock[i].setSmooth(true);
	}

	texturesGhostBlock = sf::Texture();
	if (!texturesGhostBlock.loadFromFile("resources/BlockGhost.png"))
		throw runtime_error("Load Texture Ghost Block");
	texturesGhostBlock.setSmooth(true);
}