/*
 * Author: Pascal Riesinger
 * Description: This class is just an extension of the GameObject class, which provides IDs and text (which will be displayed directly 
 * 		besides the actual icon. It is used to keep things much neater
 */

#include "icon.h"

Icon::Icon(float x, float y, float width, float height, GLuint tex) {
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setTexture(tex);
	text = "";
}

Icon::Icon(float x, float y, float width, float height, GLuint tex, short id) {
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setTexture(tex);
	ID = id;
}

Icon::Icon(float x, float y, float width, float height, GLuint tex, short id, std::string text) {
	setX(x);
	setY(y);
	setWidth(width);
	setHeight(height);
	setTexture(tex);
	this->text = text;
	ID = id;
}

std::string Icon::getText() {
	return text;
}

void Icon::setText(std::string text) {
	this->text = text;
}

short Icon::getID(){
	return ID;
}


