/*
 * Author: Pascal Riesinger
 * Description: This is the basic character class. It implements all the character mechanics such as moving to a set target
 * 		Later this class will also contain the pathfinding algorithm.
 */

#include "building.h"
#include "character.h"


#include <math.h>
#include <algorithm>
#include <iostream>
#include <SDL2/SDL_opengl.h>

//TODO: Rename this class to something better
//TODO: Implement the new texture management system

float Character::movementSpeed = 2.0f;


Character::Character(float px, float py, GLuint tex) {
    setX(px);
    setY(py);
	//Every character will have the same height and width.
    setWidth(32);
    setHeight(64);
    setTexture(tex);
	//Set the default target to none, so the character won't move
    targetX = getX();
    targetY = getY();
    distanceX = 0;
    distanceY = 0;
}

//Set the Character's destination
void Character::moveTo(float x, float y) {
	std::cout << "[CHARACTER][INFO]Now approaching target " << x << "|" << y << std::endl;
    targetX = x;
    targetY = y - getHeight();
    distanceX = getX() - targetX;
    distanceY = getY() - targetY;
}

void Character::update() {
	//Move the character closer to its destination
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
