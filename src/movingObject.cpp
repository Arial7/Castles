#include <math.h>
#include <algorithm>
#include <iostream>

#include "time.h"
#include "movingObject.h"

void MovingObject::setTarget (Point p) {
	this->target = p;
}

void MovingObject::setTarget (GameObject* obj) {
	this->target = obj->getPosition();
}

void MovingObject::setSpeed (float speed) {
	this->speed = speed;
}
 
//This function calculates the movement and returns the new coordinates of the object
Point MovingObject::move (Point coordinates) {
	//Create the point for the new coords
	Point newCoords(coordinates.getX(), coordinates.getY());
	//Calculate the movement along the x axis
	float distanceX (coordinates.getX() - target.getX());
	if(distanceX != 0) {
		short mult(1);
		if (distanceX < 0)
			mult = -1;
		float d(fabs(distanceX));
		float movingDistance = speed * Time::deltaTimeSecs();
		if (movingDistance > d)
			movingDistance = d * mult;
		else
			movingDistance *= mult;
		newCoords.setX(coordinates.getX() - movingDistance);
	}
	//Calculate the movement along the y axis
	float distanceY (coordinates.getY() - target.getY());
	if(distanceY != 0) {
		short mult(1);
		if (distanceY < 0)
			mult = -1;
		float d(fabs(distanceY));
		float movingDistance = speed * Time::deltaTimeSecs();
		if (movingDistance > d)
			movingDistance = d * mult;
		else
			movingDistance *= mult;
		newCoords.setY(coordinates.getY() - movingDistance);
	}
	
	return newCoords;

}