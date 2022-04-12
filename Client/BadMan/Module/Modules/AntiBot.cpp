#include "AntiBot.h"

AntiBot::AntiBot() : IModule(0, Category::PLAYER, "Enable this module to filter bots!") {
	registerBoolSetting("Hitbox Check", &this->hitboxCheck, this->hitboxCheck);
	//registerBoolSetting("Name Check", &this->nameCheck, this->nameCheck);
	registerBoolSetting("Invisible Check", &this->invisibleCheck, this->invisibleCheck);
	registerBoolSetting("EntityID Check", &this->entityIdCheck, this->entityIdCheck);
	registerBoolSetting("Other Check", &this->otherCheck, this->otherCheck);
	registerBoolSetting("Extra Check", &this->extraCheck, this->extraCheck);
}

AntiBot::~AntiBot() {
}

const char* AntiBot::getModuleName() {
	return ("AntiBot");
}
