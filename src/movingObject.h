#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "point.h"
#include "gameObject.h"

class MovingObject {
	public:
		void setTarget (Point p);
		void setTarget (GameObject* obj);
		void setSpeed (float speed);
		//Calculates the movement and returns the new coords
		Point move (Point coordinates);
	private:
		float speed = 1;
		Point target = Point(0,0);
};

#endif
