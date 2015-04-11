#ifndef POINT_H
#define POINT_H

class Point {
	public:
		Point();
		Point(float x, float y);
		float getX(void);
		void setX(float);
		float getY(void);
		void setY(float);
		void setCoordinates(float x, float y);
	private:
		float x;
		float y;
};

#endif