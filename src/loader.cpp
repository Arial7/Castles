#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>
#include <string>
#include <iostream>

#include "loader.h"

std::string Loader::imgPath = "res/images/";

GLuint Loader::loadTexture(std::string name) {
	std::string filepath(imgPath + name);

	GLuint texture;
	SDL_Surface *surface = IMG_Load(filepath.c_str());
	if (surface == nullptr) {
		std::cout << "[LOADER][WARN]Could not load texture: " << SDL_GetError() << std::endl;	
	}
	//generate the GL texture and tweak it a bit
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0,
				GL_RGBA, GL_UNSIGNED_BYTE, surface->pixels);
				
	//Set up scaling behaviour
	//TODO: implement mipmapping
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	//Do some cleanup
	SDL_FreeSurface(surface);
	//delete surface;
	glBindTexture(GL_TEXTURE_2D, 0);
	
	
	GLenum GLError = glGetError();
	if (GLError != GL_NO_ERROR) {
		std::cout << "[LOADER][WARN]Error loading image: " << std::endl << GLError << gluErrorString (GLError) << std::endl;
	}
	
	std::cout << "[LOADER][INFO]Loaded texture: " << name << " and created GL texture with number: " << texture << std::endl;
	return texture;
}

void Loader::deleteTexture(GLuint tex) {
	glDeleteTextures(1, &tex);
}
