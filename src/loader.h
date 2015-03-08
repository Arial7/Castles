#ifndef LOADER_H
#define LOADER_H

#include <SDL2/SDL_opengl.h>
#include <string>

class Loader {
	public:
		GLuint loadTexture(std::string name);
		void deleteTexture(GLuint tex);
	private:
		static std::string imgPath;
};

#endif
