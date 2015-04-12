#ifndef TOWEROBJECT_H
#define TOWEROBJECT_H

#include <vector>
#include "character.h"
#include "point.h"

class TowerObject {
	public: 
		void update(std::vector <Character*> characters);
		void setTowerPosition(Point p);
		void setSpeed(float speed);
		void setRange(float range);
		void setDamage(float damage);
		float getSpeed(void);
		float getRange(void);
		float getDamage(void);		
	private:
		float speed = 1;
		float range = 5;
		float damage = 1;
		void shoot(std::vector <Character*> characters);
		Point position;
};

#endif
