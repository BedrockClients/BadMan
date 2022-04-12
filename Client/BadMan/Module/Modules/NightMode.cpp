#include "NightMode.h"

NightMode::NightMode() : IModule(0, Category::VISUAL, "Darkens the environment") {
	//registerFloatSetting("modifier", &this->modifier, this->modifier, 0.1f, 1.f);
}

NightMode::~NightMode() {
}

const char* NightMode::getModuleName() {
	return "NightMode";
}

void NightMode::onEnable() {
	static auto CustomSkyMod = moduleMgr->getModule<CustomSky>();
	if (CustomSkyMod->isEnabled())
		CustomSkyMod->setEnabled(false);
}