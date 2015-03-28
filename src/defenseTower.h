#ifndef DEFENSETOWER_H
#define DEFENSETOWER_H

#include <vector>
#include "building.h"
#include "character.h"


class DefenseTower : public Building {
	public:
		DefenseTower (float x, float y, float damage, float speed, float range);
		void update (std::vector <Character*> characters); 
	private:
		float damage;
		float speed;
		float range;

};

#endif
