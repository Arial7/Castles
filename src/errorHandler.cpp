#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>
#include <GL/glu.h>
#include <iostream>

#include "errorHandler.h"


//GLEnum ErrorHandler::GLError(GL_NO_ERROR);

void ErrorHandler::logSDLError(std::ostream &os, const std::string &msg){
	os << msg << " error: " << SDL_GetError() << std::endl;
}

bool ErrorHandler::checkGLError(){
	ErrorHandler::GLError = glGetError();
	if (GLError != GL_NO_ERROR) {
		std::cout << "Error initializing OpenGL!" << std::endl << GLError << gluErrorString (GLError) << std::endl;
		return true;
	}
	else {
		return false;
	}
}

