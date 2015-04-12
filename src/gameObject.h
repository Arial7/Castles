#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL_opengl.h>
#include "point.h"

class GameObject {

	public:
		GameObject(void);
		GameObject(Point position, float width, float height);
		//float getX(void);
		//float getY(void);
		float getWidth(void);
		float getHeight(void);
		Point getPosition(void);
		bool isPointInside(float x, float y);
		GLuint getTexture(void);
		void setX(float x);
		void setY(float y);
		void setWidth(float width);
		void setHeight(float height);
		void setPosition(Point p);
		void setTexture(GLuint texture);
	private:
		GLuint texture;
	protected:
		Point position = Point(0,0);
		float width;
		float height;
};


#endif
