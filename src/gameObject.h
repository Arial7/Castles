#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL_opengl.h>

class GameObject {

	public:
		GameObject(void);
		GameObject(float x, float y, float width, float height);
		float getX(void);
		float getY(void);
		float getWidth(void);
		float getHeight(void);
		bool isPointInside(float x, float y);
		GLuint getTexture(void);
		void setX(float x);
		void setY(float y);
		void setWidth(float width);
		void setHeight(float height);
		void setPosition(float x, float y);
		void setTexture(GLuint texture);
	private:
		float x;
		float y;
		float width;
		float height;
		GLuint texture;
};


#endif
