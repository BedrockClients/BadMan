#include "FastLadder.h"

FastLadder::FastLadder() : IModule(0, Category::MOVEMENT, "Climb up ladders faster") {
}

FastLadder::~FastLadder() {
}

const char* FastLadder::getModuleName() {
	return ("FastLadder");
}
