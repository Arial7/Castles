#ifndef TEXTURES_H
#define TEXTURES_H

#include <SDL2/SDL_opengl.h>
#include "loader.h"

class Textures {
	public:
		Textures(Loader* loader);
		Loader* loader;
		void loadTextures (void);
		void deleteTextures (void);
		GLuint icon_health;
		GLuint icon_play;
		GLuint icon_pause;

		GLuint building_mainTower;
		GLuint character_default;

};

#endif
