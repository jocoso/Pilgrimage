#include "../include/ccsystem.h"

CharacterCreationSystem::~CharacterCreationSystem() {}

void CharacterCreationSystem::run() {
	std::cout << "CHARACTER-CREATION_SYSTEM: 10%" << std::endl;
	_components["io"]->activate();
}

