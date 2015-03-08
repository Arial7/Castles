#ifndef ICON_H
#define ICON_H

#include "gameObject.h"
#include <string>

class Icon : public GameObject {
	public:
		Icon(float x, float y, float width, float height, GLuint tex);
		Icon(float x, float y, float width, float height, GLuint tex, short id);
		Icon(float x, float y, float width, float height, GLuint tex, short id, std::string iconText);
		std::string getText(void);
		void setText(std::string newText);
		short getID(void);
	private:
		std::string text;
		short ID;
};

#endif
