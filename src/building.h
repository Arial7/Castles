#ifndef BUILDING_H
#define BUILDING_H

#include "gameObject.h"
#include "icon.h"
#include <vector>
#include <SDL2/SDL_opengl.h>


class Building : public GameObject {
	public:
		Building(float x, float y, int shealth, bool isUpgradable, GLuint tex, GLuint hammerIconTex);
		Building();
		~Building();
		void setSelected(bool s);
		void setHealth(int newHealth);
		void setUpgradable(bool u);
		int getHealth(void);
		bool isUpgradable(void);
		bool isSelected(void);
		std::vector <Icon*> getIcons(void);
	private:
		int health;
		bool selected;
		bool upgradable;
		std::vector <Icon*> icons;
};

#endif

