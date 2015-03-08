#include "textures.h"

Textures::Textures(Loader* loader) {
	this->loader = loader;
}

void Textures::loadTextures() {
	icon_health = loader->loadTexture("icon_health.png");
	icon_play = loader->loadTexture("icon_play.png");
	icon_pause = loader->loadTexture("icon_pause.png");

	building_mainTower = loader->loadTexture("building_mainTower.png");

	character_default = loader->loadTexture("character_default.png");

}

void Textures::deleteTextures() {
	loader->deleteTexture(icon_health);
	loader->deleteTexture(icon_play);
	loader->deleteTexture(icon_pause);

	loader->deleteTexture(building_mainTower);

	loader->deleteTexture(character_default);

}


