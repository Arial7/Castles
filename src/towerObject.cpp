#include "towerObject.h"
#include "time.h"
#include "utils.h"
#include "gameObject.h"

#include <iostream>

static int delay = 0;

void TowerObject::update(std::vector <Character*> characters) {
	delay += Time::deltaTime();
	if (delay >= 1000/speed) {
		delay = 0;
		shoot(characters);
	}
}

void TowerObject::shoot(std::vector <Character*> characters) {
	for (Character* c : characters) {
		if (Utils::squareInCircle(c->getPosition(), c->getWidth(), c->getHeight(), position, range)) {
			c->damage(damage);
			std::cout << "[TOWEROBJECT][INFO] Damaging player" << std::endl;
		}	
	}

}

void TowerObject::setTowerPosition(Point p) {
	position = p;
}

void TowerObject::setSpeed(float speed){
	this->speed = speed;
}

void TowerObject::setRange(float range){
	this->range = range;
}

void TowerObject::setDamage(float damage){
	this->damage = damage;
}

float TowerObject::getSpeed() {
	return speed;
}

float TowerObject::getRange() {
	return range;
}

float TowerObject::getDamage() {
	return damage;
}
