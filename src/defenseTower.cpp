#include "defenseTower.h"
#include <iostream>

void DefenseTower::update(std::vector <Character*> characters) {
	for (Character* character : characters) {
		if (character->getX() <= this->getX() + this->getRadius() && character->getX() + character->getWidth() >= this->getX() - this->getRadius()) {
			if (character->getY() >= this->getY() - this->getRadius() && character->getY() + character->getHeight() <= this->getY() + this->getRadius()) {
				std::cout << "[DefenseTower] Character in range found" << std::endl;
			}
		}
	}
}

float DefenseTower::getRadius() {
	return radius;
}

void DefenseTower::setRadius(float radius) {
	this->radius = radius;
}

float DefenseTower::getDamage() {
	return damage;
}

void DefenseTower::setDamage(float damage) {
	this->damage = damage;
}


float DefenseTower::getSpeed() {
	return speed;
}

void DefenseTower::setSpeed(float speed) {
	this->speed = speed;
}




