#include "archerTower.h"
#include "point.h"
#include "textures.h"

ArcherTower::ArcherTower(float x, float y, float tier){
	setPosition(Point(x, y));
	setTexture(Textures::building_mainTower);
	setTowerPosition(getPosition());
	setSpeed(1);
	setRange(5);
	setDamage(10);
}
