/*
 * Author: Pascal Riesinger
 * Description: This class is a base class that implements all the basic building functionalities
 *		For example it implements the health and upgrade system. Every building in the game inherits from this class
 */

#include "building.h"
#include "icon.h"
#include "character.h"

#include <iostream>


//Default constructor, which sets all the values to their default
Building::Building() {
	setX(0);
	setY(0);
	setWidth(64);
	setHeight(64);
	setHealth(999);
	setUpgradable(false);
}
//Main constructor, which receives all the values and sets the variables to them
//TODO: Use the this pointer and make Variable names more awesome
//TODO: Implement the new texture management system
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
//The dstructor just cleans up all the icons
Building::~Building(){
	for(Icon* icon : icons) {
		delete icon;
	}
}

/*GETTERS & SETTERS*/

//Change the selection mode. This is used for the upgrade UI
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
