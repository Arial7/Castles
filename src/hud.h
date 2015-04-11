#ifndef HUD_H
#define HUD_H

#include <vector>
#include "gameObject.h"
#include "icon.h"
#include "textures.h"

class HUD {
	private:
		Icon* getIcon(short ID);
		std::vector <Icon*> icons;
		
		short healthIconID = 0;
		short playPauseIconID = 1;
		int health;
		bool paused = false;
	public:
		HUD ();
		void setHealth (int health);
		void changePlayStatus();
		std::vector <Icon*> getIcons(void);

};

#endif
