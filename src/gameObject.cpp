#include "gameObject.h"

GameObject::GameObject(){
	x = 0;
	y = 0;
	width = 32;
	height = 32;
}

GameObject::GameObject(float px, float py, float pwidth, float pheight){
	x = px;
	y = py;
	width = pwidth;
	height = pheight;
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

void GameObject::setX(float newx){
	x = newx;
}

void GameObject::setY(float newy){
	y = newy;
}

void GameObject::setWidth(float newwidth){
	width = newwidth;
}

void GameObject::setHeight(float newheight){
	height = newheight;
}

void GameObject::setPosition(float newx, float newy){
	x = newx;
	y = newy;
}

void GameObject::setTexture(GLuint tex) {
	texture = tex;
}

bool GameObject::isPointInside(float x, float y) {
	if(x >= getX() && x <= getX() + getWidth() && y >= getY() && y <= getY() + getHeight())
		return true;
	return false;
}


