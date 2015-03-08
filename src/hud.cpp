#include "hud.h"
#include <string>

HUD::HUD (GLuint icon_health) {
	icons.emplace_back(new Icon(2, 2, 32, 32, icon_health, healthIconID, "0"));
}

void HUD::setHealth (int health) {
	this->health = health;
	for (Icon* icon : icons) {
		if (icon->getID() == healthIconID) {
			std::string str = std::to_string(this->health);
			icon->setText(str);
			break;
		}
	}
}

std::vector <Icon*> HUD::getIcons() {
	return icons;
}


