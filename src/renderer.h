#ifndef RENDERER_H
#define RENDERER_H


#include <SDL2/SDL.h>
#include <FTGL/ftgl.h>
#include <iostream>
#include <string>

#include "gameObject.h"
#include "character.h"
#include "hud.h"

class Renderer{
    public:
    	Renderer(float wHeight);
        void renderObject(GameObject* obj);
        void renderObject(HUD* hud);
        void renderCharacter(Character* obj);
        void renderText(std::string text, float x, float y);
    private:
		static FTPixmapFont *font;
		float windowHeight;
};

#endif
