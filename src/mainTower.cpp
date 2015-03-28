/*
 * Author: Pascal Riesinger
 * Description: This is the class for the main tower, all the enemys are going to attack
 */

#include "mainTower.h"
#include "building.h"

MainTower::MainTower(float x, float y, int health, GLuint tex) {
	setX(x);
	setY(y);
	setWidth(64);
	setHeight(128);
	setHealth(health);
	setTexture(tex);
	setUpgradable(false);
}

void MainTower::damage(int dmg) {
	setHealth(getHealth() - dmg);
}


