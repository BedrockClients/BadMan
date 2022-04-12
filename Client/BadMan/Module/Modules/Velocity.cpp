#include "Velocity.h"

Velocity::Velocity() : IModule(0, Category::MOVEMENT, "anti kb ez") {
	this->registerFloatSetting("Linear Modifier", &this->xModifier, this->xModifier, 0.f, 1.f);
	this->registerFloatSetting("Height Modifier", &this->yModifier, this->yModifier, 0.f, 1.f);
}

Velocity::~Velocity() {
}

const char* Velocity::getModuleName() {
	return ("Velocity");
}


void Velocity::onTick(C_GameMode* gm) {
}