#include <iostream>

#include "point.h"

Point::Point () {
	std::cout << "[POINT][WARN]Creating a point without coordinates, defaulting to 0|0" << std::endl;
	this->x = 0;
	this->y = 0;
}

Point::Point (float x, float y) {
	this->x = x;
	this->y = y;
}

float Point::getX () {
	return x;
}

void Point::setX (float x) {
	this->x = x;
}

float Point::getY () {
	return y;
}

void Point::setY (float y) {
	this->y = y;
}

void Point::setCoordinates (float x, float y) {
	this->x = x;
	this->y = y;
}
