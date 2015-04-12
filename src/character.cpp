/*
 * Author: Pascal Riesinger
 * Description: This is the basic character class. It implements all the character mechanics such as moving to a set target
 * 		Later this class will also contain the pathfinding algorithm.
 */

#include "character.h"
#include "textures.h"

#include <math.h>
#include <algorithm>
#include <iostream>
#include <SDL2/SDL_opengl.h>

//TODO: Rename this class to something better
//TODO: Cleanup (imports, move some code to MovingObject)

float Character::movementSpeed = 2.0f;


Character::Character(float px, float py, float health) {
    setX(px);
    setY(py);
	//Every character will have the same height and width.
    setWidth(32);
    setHeight(64);
    setTexture(Textures::character_default);
    this->health = health;
    setSpeed(movementSpeed);
	//Set the default target to none, so the character won't move
	setTarget(Point(px, py));
}


void Character::update() {
	//Move the character closer to its destination
	setPosition(move(position));

}

bool Character::hasReachedDestiny() {
	return false;
}

bool Character::isInRadius(float x, float y, float radius) {
	//TODO: implement checking algorithm
	return false;
}

void Character::damage(float dmg) {
	this->health -= dmg;
}

bool Character::isDead() {
	return (this->health <= 0);
}
