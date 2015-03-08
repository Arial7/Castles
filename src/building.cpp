#include "building.h"
#include "icon.h"
#include "character.h"

#include <iostream>

Building::Building() {
	setX(0);
	setY(0);
	setWidth(64);
	setHeight(64);
	setHealth(999);
	setUpgradable(false);
	
}

Building::Building(float x, float y, int shealth, bool isUpgradable, GLuint tex, GLuint hammerIconTex) {
	setX(x);
	setY(y);
	health = shealth;
	upgradable = isUpgradable;
	setTexture(tex);

	setWidth(128);
	setHeight(128);
	selected = false;

	icons.emplace_back(new Icon(getX() + 64, getY() - 32, 32, 32, hammerIconTex, 2, std::to_string(1)));
}

Building::~Building(){
	for(Icon* icon : icons) {
		delete icon;
	}
}

void Building::setSelected(bool s) {
	selected = s;
}

void Building::setHealth(int newHealth) {
	health = newHealth;
}

void Building::setUpgradable(bool u) {
	upgradable = u;
}

int Building::getHealth() {
	return health;
}

bool Building::isUpgradable() {
	return upgradable;
}

bool Building::isSelected() {
	return selected;
}

std::vector <Icon*> Building::getIcons() {
	return icons;
}
