#ifndef CHARACTER_H
#define CHARACTER_H

#include <SDL2/SDL_opengl.h>
#include "gameObject.h"
#include "movingObject.h"

class Character : public GameObject, public MovingObject {
    public:
        Character(float px, float py, float health);
        void update(void);
        bool hasReachedDestiny(void);
        bool isInRadius(float x, float y, float radius);
        void damage(float dmg);
        bool isDead(void);
    private:
    	static float movementSpeed;
		float targetX;
   	 	float targetY;
   	  	float distanceX;
		float distanceY;
		float health;


};

#endif
