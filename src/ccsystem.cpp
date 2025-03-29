#include "../include/ccsystem.h"

CharacterCreationSystem::~CharacterCreationSystem() {}

void CharacterCreationSystem::run() {
	_components["io"]->use_function("write", "Hello World!");
}

