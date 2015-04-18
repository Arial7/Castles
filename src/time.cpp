#include "time.h"
#include <SDL2/SDL.h>
#include <iostream>
//Workaround for "undefined reference"
static long lastTime = 0;
static long currentTime = 0;
static long delta = 0;

void Time::init() {
	lastTime = SDL_GetTicks();
	currentTime = SDL_GetTicks();	
	delta = 0;
}

void Time::update() {
	currentTime = SDL_GetTicks();
	delta = currentTime - lastTime;
	lastTime = currentTime;
}

long Time::deltaTime() {
	return delta;
}

float Time::deltaTimeSecs() {
	return delta / 1000.0f;
}
