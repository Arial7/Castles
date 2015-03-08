#ifndef HUD_H
#define HUD_H

#include <vector>
#include "gameObject.h"
#include "icon.h"

class HUD {
	private:
		std::vector <Icon*> icons;
		short healthIconID = 0;
		short playPauseIconID = 1;
		int health;
	public:
		HUD (GLuint icon_health, GLuint icon_play, GLuint icon_pause);
		void setHealth (int health);
		std::vector <Icon*> getIcons(void);

};

#endif
