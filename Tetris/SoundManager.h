#ifndef SOUND_MANAGER_DEF
#define SOUND_MANAGER_DEF

#include <SFML/Audio.hpp>

class SoundManager {
public:
	sf::Music musicFond;
	sf::SoundBuffer bufferSonTomber, bufferSonGameOver,  bufferSonPause;
	sf::Sound sonTomber, sonGameOver, sonPause;
	bool isGameOver = false;

	SoundManager();
	void pause();
	void play();
	void tomber();
	void gameOver();
};

#endif // !SOUND_MANAGER_DEF