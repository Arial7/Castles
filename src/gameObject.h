#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL2/SDL_opengl.h>

class GameObject {

	public:
		GameObject(void);
		GameObject(float px, float py, float pwidth, float pheight);
		float getX(void);
		float getY(void);
		float getWidth(void);
		float getHeight(void);
		bool isPointInside(float x, float y);
		GLuint getTexture(void);
		void setX(float newx);
		void setY(float newy);
		void setWidth(float newwidth);
		void setHeight(float newheight);
		void setPosition(float newx, float newy);
		void setTexture(GLuint tex);
	private:
		float x;
		float y; 
		float width;
		float height;
		GLuint texture;
}; 	


#endif
