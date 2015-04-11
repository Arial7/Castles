#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL_opengl.h>
#include "loader.h"

class Textures {
	public:
		static void loadTextures (void);
		static void deleteTextures (void);
		static GLuint icon_health;
		static GLuint icon_play;
		static GLuint icon_pause;

		static GLuint building_mainTower;
		static GLuint character_default;

};

#endif
