/*
 * Author: Pascal Riesinger
 * Description: This is the root class for all the objects in the game. It provides basic functionality such as getters and setters for
 * 		the coordinates and dimensions.
 */

#include "gameObject.h"


//TODO:implement the new point thingy

GameObject::GameObject(){
	position.setCoordinates(0, 0);
	width = 32;
	height = 32;
}

GameObject::GameObject(Point position, float width, float height){
	this->position = position;
	this->width = width;
	this->height = height;
}


/*float GameObject::getX(){
	return position.getX();
}

float GameObject::getY(){
	return position.getY();
}
*/

Point GameObject::getPosition(){
	return position;
}

float GameObject::getWidth(){
	return width;
}

float GameObject::getHeight(){
	return height;
}

GLuint GameObject::getTexture() {
	return texture;
}

void GameObject::setX(float x){
	position.setX(x);
}

void GameObject::setY(float y){
	position.setY(y);
}

void GameObject::setWidth(float width){
	this->width = width;
}

void GameObject::setHeight(float height){
	this->height = height;
}

void GameObject::setPosition(Point position){
	this->position = position;
}

void GameObject::setTexture(GLuint texture) {
	this->texture = texture;
}

bool GameObject::isPointInside(float x, float y) {
	if(x >= position.getX() && x <= position.getX() + getWidth() && y >= position.getY() && y <= position.getY() + getHeight())
		return true;
	return false;
}


