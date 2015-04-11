/*
 * Author: Pascal Riesinger
 * Description: This class is used to load textures, sound files, images, etc... into a usable format
 *		It also provides functions to destroy all these objects later on
 */

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <SDL2/SDL_image.h>
#include <GL/glu.h>
#include <string>
#include <iostream>

#include "loader.h"

//TODO: cleanup

//This is the path of the images location
std::string Loader::imgPath = "res/images/";

//This function takes in an texture file name and returns the GLuint pointing to the OpenGL texture
//TODO: implement mipmapping
GLuint Loader::loadTexture(std::string name) {
	std::string filepath(imgPath + name);
	//This will hold the actual OpenGL texture number
	GLuint texture;
	//Load the image to an SDL_Surface
	SDL_Surface *surface = IMG_Load(filepath.c_str());
	if (surface == nullptr) {
		std::cout << "[LOADER][WARN]Could not load texture: " << filepath << " : " << SDL_GetError() << std::endl;
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

	//Bind the default "NULL" texture again, so no faulty texture rendering might appear
	glBindTexture(GL_TEXTURE_2D, 0);

	//Check if there are any OpenGL errors in the pipeline
	GLenum GLError = glGetError();
	if (GLError != GL_NO_ERROR) {
		std::cout << "[LOADER][WARN]Error loading image: " << std::endl << GLError << gluErrorString (GLError) << std::endl;
	}
	//Print some information about the loaded texture. This is mainly for debugging
	std::cout << "[LOADER][INFO]Loaded texture: " << filepath << std::endl;
	return texture;
}

void Loader::deleteTexture(GLuint tex) {
	glDeleteTextures(1, &tex);
}
