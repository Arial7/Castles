/*
 * Author: Pascal Riesinger
 * Description: This is the root class for all the objects in the game. It provides basic functionality such as getters and setters for
 * 		the coordinates and dimensions.
 */

#include "gameObject.h"

GameObject::GameObject(){
	x = 0;
	y = 0;
	width = 32;
	height = 32;
}

GameObject::GameObject(float x, float y, float width, float height){
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}


float GameObject::getX(){
	return x;
}

float GameObject::getY(){
	return y;
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
	this->x = x;
}

void GameObject::setY(float y){
	this->y = y;
}

void GameObject::setWidth(float width){
	this->width = width;
}

void GameObject::setHeight(float height){
	this->height = height;
}

void GameObject::setPosition(float x, float y){
	this->x = x;
	this->y = y;
}

void GameObject::setTexture(GLuint texture) {
	this->texture = texture;
}

bool GameObject::isPointInside(float x, float y) {
	if(x >= getX() && x <= getX() + getWidth() && y >= getY() && y <= getY() + getHeight())
		return true;
	return false;
}


