#ifndef DEFENSETOWER_H
#define DEFENSETOWER_H

#include <vector>
#include "building.h"
#include "character.h"
class DefenseTower : public Building {
	public:
		void update(std::vector <Character*> characters);
	private:
		int radius = 5;
		int speed = 3;
		int damage = 10;
		std::vector <Character*> charactersInRange;
};

#endif
