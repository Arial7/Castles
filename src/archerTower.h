#ifndef ARCHERTOWER_H
#define ARCHERTOWER_H

#include "gameObject.h"
#include "towerObject.h"

class ArcherTower : public GameObject, public TowerObject {
	public:
		ArcherTower(float x, float y, float tier);
};

#endif

