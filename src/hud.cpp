/*
 * Author: Pascal Riesinger
 * Description: This class resembles the main user interface, such as the health of the main tower, the money the player has, etc..
 */

#include "hud.h"
#include <string>
#include <iostream>

HUD::HUD (Textures* textures) {
	this->textures = textures;
	//Create the icons used (for now, there is the health icon and the play/pause icon)
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
	//Change the icon according to the current game state
	if (paused) getIcon(playPauseIconID)->setTexture(textures->icon_pause);
	else getIcon(playPauseIconID)->setTexture(textures->icon_play);
}

//Returns the icon with the given ID
Icon* HUD::getIcon(short ID) {
	for (Icon* icon : icons) {
		if (icon->getID() == ID) {
			return icon;
		}
	}
	//If there was no icon with the given ID, print an error message to the screen and return a nullptr (basically the game will crash here).
	std::cout << "[HUD][FATAL]tried to acces an icon with ID " << ID << ", but this icon didn't exist" << std::endl;
	return nullptr;
}

