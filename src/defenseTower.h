#ifndef DEFENSETOWER_H
#define DEFENSETOWER_H

#include "building.h"
#include "character.h"
#include <vector>

class DefenseTower : public Building {
	public:
		void update(std::vector <Character*> characters);
		float getRadius(void);
		void setRadius(float radius);
		float getDamage(void);
		void setDamage(float damage);
		float getSpeed(void);
		void setSpeed(float speed);
	private:
		float radius;
		float damage;
		float speed;
		int level;
		std::vector <Character*> charactersInRange;


};

#endif
