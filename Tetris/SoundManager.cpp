#include "SoundManager.h"

using namespace std;

SoundManager::SoundManager() {
	if (!musicFond.openFromFile("resources/tetris.ogg"))
		throw runtime_error("open Music Fond");
	musicFond.setVolume(25);
	musicFond.setLoop(true);
	
	if (!bufferSonPause.loadFromFile("resources/soundPause.wav"))
		throw runtime_error("Load Sound Pause");

	if (!bufferSonTomber.loadFromFile("resources/soundTomber.ogg"))
		throw runtime_error("Load Sound Tomber");

	if (!bufferSonGameOver.loadFromFile("resources/gameover.wav"))
		throw runtime_error("Load Sound Tomber");

	sonPause.setBuffer(bufferSonPause);
	sonTomber.setBuffer(bufferSonTomber);
	sonGameOver.setBuffer(bufferSonGameOver);
}

void SoundManager::mute() {
	if(musicFond.getVolume() > 0)
		musicFond.setVolume(0);
	else
		musicFond.setVolume(25);
}

void SoundManager::tomber() {
	sonTomber.play();
}

void SoundManager::play() {
	musicFond.play();
	isGameOver = false;
}

void SoundManager::pause() {
	sonPause.play();
	if (musicFond.getStatus() == sf::Music::Paused)
		musicFond.play();
	else
		musicFond.pause();
}

void SoundManager::gameOver() {
	musicFond.stop();
	if (!isGameOver) {
		sonGameOver.play();
		isGameOver = true;
	}
}