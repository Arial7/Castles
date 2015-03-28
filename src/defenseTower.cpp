#include "defenseTower.h"
#include <iostream>

DefenseTower::DefenseTower(float x, float y, float damage, float speed, float range) {
	setX(x);
	setY(y);
	this->damage = damage;
	this->speed = speed;
	this->range = range;
}

void DefenseTower::update(std::vector <Character*> characters) {
	for (Character* c : characters) {
		if (c->isInRadius(getX(), getY(), this->range)) {
			c->damage(this->damage);
			std::cout << "[DEFENSETOWER][INFO]Destroyed Character" << std::endl;
			return;
		}
	}
}

