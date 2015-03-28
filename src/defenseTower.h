#ifndef DEFENSETOWER_H
#define DEFENSETOWER_H

#include <vector>
#include "building.h"
#include "character.h"
<<<<<<< HEAD

class DefenseTower : public Building {
	public:
		DefenseTower (float x, float y, float damage, float speed, float range);
		void update (std::vector <Character*> characters); 
	private:
		float damage;
		float speed;
		float range;
=======
class DefenseTower : public Building {
	public:
		void update(std::vector <Character*> characters);
	private:
		int radius = 5;
		int speed = 3;
		int damage = 10;
		std::vector <Character*> charactersInRange;
>>>>>>> 7154fdc3b8b2ea82791939ea437a376222792298
};

#endif
