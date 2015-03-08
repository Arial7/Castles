#ifndef MAINTOWER_H
#define MAINTOWER_H

#include "building.h"
#include <SDL2/SDL_opengl.h>

class MainTower : public Building{
	public:
		MainTower(float x, float y, int health, GLuint tex);
		void damage(int dmg);
	private:
};
#endif
