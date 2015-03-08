#include "hud.h"
#include <string>

HUD::HUD (Textures* textures) {
	this->textures = textures;
	icons.emplace_back(new Icon(2, 2, 32, 32, textures->icon_health, healthIconID, "0"));
	icons.emplace_back(new Icon(1280 - 32, 2, 32, 32, textures->icon_play, playPauseIconID));
}

void HUD::setHealth (int health) {
	this->health = health;
	//Find the health icon and set its text attribute to the current health
	getIcon(healthIconID)->setText(std::to_string(this->health));
}

std::vector <Icon*> HUD::getIcons() {
	return icons;
}

void HUD::changePlayStatus() {
	paused = !paused;
	if (paused) getIcon(playPauseIconID)->setTexture(textures->icon_pause);
	else getIcon(playPauseIconID)->setTexture(textures->icon_play);
}

Icon* HUD::getIcon(short ID) {
	for (Icon* icon : icons) {
		if (icon->getID() == ID) {
			return icon;
		}
	}
	return nullptr;
}

