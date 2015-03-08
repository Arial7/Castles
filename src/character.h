#ifndef CHARACTER_H
#define CHARACTER_H

#include "building.h"
#include <SDL2/SDL_opengl.h>

class Character : public GameObject{
    public:
        Character(float px, float py, GLuint tex);
        void update(void);
        void moveTo(float x, float y);
        bool hasReachedDestiny(void);
    private:
    	static float movementSpeed;
        float targetX;
   		float targetY;
   		float distanceX;
		float distanceY;
};

#endif
