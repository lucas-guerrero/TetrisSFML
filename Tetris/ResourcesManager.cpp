#include "ResourcesManager.h"
#include <sstream>

using namespace std;

ResourcesManager::ResourcesManager() {
	texturesBlock = array<sf::Texture, NB_TEXTURE_BLOCK>();

	stringstream ss;

	for (int i = 0; i < NB_TEXTURE_BLOCK; ++i) {
		ss << "resources/tetris" << i << ".png";
		if (!texturesBlock[i].loadFromFile(ss.str()))
			throw runtime_error("Load Texture Block");
		ss.str(string());
		texturesBlock[i].setSmooth(true);
	}

	if (!texturesGhostBlock.loadFromFile("resources/BlockGhost.png"))
		throw runtime_error("Load Texture Ghost Block");
	texturesGhostBlock.setSmooth(true);

	if (!textureFond.loadFromFile("resources/fond.jpg"))
		throw runtime_error("Load Texture Fond");

	if (!fontClassique.loadFromFile("resources/ARCADE_N.TTF"))
		throw runtime_error("Load Font Classic");
}