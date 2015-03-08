#include "building.h"
#include "character.h"


#include <math.h>
#include <algorithm>
#include <iostream>
#include <SDL2/SDL_opengl.h>

float Character::movementSpeed = 2.0f;


Character::Character(float px, float py, GLuint tex) {
    setX(px);
    setY(py);
    setWidth(32);
    setHeight(64);
    setTexture(tex);
    targetX = getX();
    targetY = getY();
    distanceX = 0;
    distanceY = 0;
}

void Character::moveTo(float x, float y) {
	std::cout << "[CHARACTER][INFO]Now approaching target " << x << "|" << y << std::endl;
    targetX = x;
    targetY = y - getHeight();
    distanceX = getX() - targetX;
    distanceY = getY() - targetY;
}

void Character::update() {
	if(distanceX != 0) {
		short mult(1);
		if (distanceX < 0)
			mult = -1;
		float d(fabs(distanceX));
		float movingDistance = std::min(d, movementSpeed) * mult;
		setX(getX() - movingDistance);
		distanceX -= movingDistance;
	}
	if(distanceY != 0) {
		short mult(1);
		if (distanceY < 0)
			mult = -1;
		float d(fabs(distanceY));
		float movingDistance = std::min(d, movementSpeed) * mult;
		setY(getY() - movingDistance);
		distanceY -= movingDistance;
	}
}

bool Character::hasReachedDestiny() {
	if (getX() == targetX && getY() == targetY)
		return true;
	return false;
}
