#ifndef ARCHERTOWER_H
#define ARCHERTOWER_H

#include <vector>
#include "building.h"
#include "character.h"
class ArcherTower : public Building {
	public:
		void update(std::vector <Character*> characters);
	private:
		int radius = 5;
		int speed = 3;
		int damage = 10;
		std::vector <Character*> charactersInRange;
};

#endif
