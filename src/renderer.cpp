/*
 * Author: Pascal Riesinger
 * Description: This is the main rendering class and the only class that can actually draw something on the screen
 */

#include "renderer.h"
#include <iostream>

//TODO: a whole lot of cleanup!!!

FTPixmapFont* Renderer::font;

Renderer::Renderer(float wHeight) {
	//load the font
	std::string fontPath("res/VCR_OSD_MONO.ttf");
    font = new FTPixmapFont(fontPath.c_str());
	if(font->Error())
		std::cerr << "[RENDERER][WARN]Could not load font " << fontPath << std::endl;
	font->FaceSize(20);
	//this will be used for the correct font placement later
	windowHeight = wHeight;
}

void Renderer::renderText(std::string text, float x, float y){
	int length(text.length());
	//We need to flip the y coodinate, because FTGL y = 0 is at the bottom of the screen
	FTPoint position(x, windowHeight - y - (font->FaceSize() / 2));
	FTPoint spacing(0,0);
	font->Render(text.c_str(), length, position, spacing, FTGL::RENDER_ALL);
}
//A general rendering method
void Renderer::renderObject(GameObject* obj){
    glColor3f(1.0f, 1.0f, 0.5f);
    glBegin(GL_QUADS);
        glVertex2f(obj->getPosition().getX(), obj->getPosition().getY());
        glVertex2f(obj->getPosition().getX() + obj->getWidth(), obj->getPosition().getY());
        glVertex2f(obj->getPosition().getX() + obj->getWidth(), obj->getPosition().getY() + obj->getHeight());
        glVertex2f(obj->getPosition().getX(), obj->getPosition().getY() + obj->getHeight());
    glEnd();
}

void Renderer::renderObject(HUD* hud){
	glColor3f(0.2, 0.2, 0.2);
	glBegin(GL_QUADS);
	glVertex2f(0, 0);
	glVertex2f(1280, 0);
	glVertex2f(1280, 40);
	glVertex2f(0, 40);
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
	for (Icon* icon : hud->getIcons()) {
		glBindTexture(GL_TEXTURE_2D, icon->getTexture());
		glBegin(GL_QUADS);
		glColor4f(1.0,1.0,1.0,1.0);
			glTexCoord2i(0, 0); glVertex2f(icon->getPosition().getX(), icon->getPosition().getY());
			glTexCoord2i(1, 0); glVertex2f(icon->getPosition().getX() + icon->getWidth(), icon->getPosition().getY());
			glTexCoord2i(1, 1); glVertex2f(icon->getPosition().getX() + icon->getWidth(), icon->getPosition().getY() + icon->getHeight());
			glTexCoord2i(0, 1); glVertex2f(icon->getPosition().getX(), icon->getPosition().getY() + icon->getHeight());
		glEnd();
		glBindTexture(GL_TEXTURE_2D, 0);
		if(icon->getText() != "") {
			//TODO: move the text location calculation to the icon iteself, because this will only need to be calculated once
			renderText(icon->getText(), icon->getPosition().getX() + icon->getWidth() + 2, icon->getPosition().getY() + (icon->getHeight() / 2));
		}
	}
}

void Renderer::renderCharacter(Character* obj) {
	glBindTexture(GL_TEXTURE_2D, obj->getTexture());
	glColor4f(1.0, 1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glTexCoord2i(0, 0); glVertex2f(obj->getPosition().getX(), obj->getPosition().getY());
	glTexCoord2i(1, 0); glVertex2f(obj->getPosition().getX() + obj->getWidth(), obj->getPosition().getY());
	glTexCoord2i(1, 1);	glVertex2f(obj->getPosition().getX() + obj->getWidth(), obj->getPosition().getY() + obj->getHeight());
	glTexCoord2i(0, 1); glVertex2f(obj->getPosition().getX(), obj->getPosition().getY() + obj->getHeight());
	glEnd();
	glBindTexture(GL_TEXTURE_2D, 0);
}


