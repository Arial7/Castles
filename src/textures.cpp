#include "textures.h"

GLuint Textures::icon_health = 0;
GLuint Textures::icon_play = 0;
GLuint Textures::icon_pause = 0;
GLuint Textures::building_mainTower = 0;
GLuint Textures::character_default = 0;

void Textures::loadTextures() {
	icon_health = Loader::loadTexture("icon_health.png");
	icon_play = Loader::loadTexture("icon_play.png");
	icon_pause = Loader::loadTexture("icon_pause.png");

	building_mainTower = Loader::loadTexture("building_mainTower.png");

	character_default = Loader::loadTexture("character_default.png");

}

void Textures::deleteTextures() {
	Loader::deleteTexture(icon_health);
	Loader::deleteTexture(icon_play);
	Loader::deleteTexture(icon_pause);

	Loader::deleteTexture(building_mainTower);

	Loader::deleteTexture(character_default);

}


