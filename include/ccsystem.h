#ifndef CC_SYSTEM_H
#define CC_SYSTEM_H

#include <iostream>
#include "iocomponent.h"
#include "system.h"

class CharacterCreationSystem : public System {
public:
	virtual ~CharacterCreationSystem();
	void run() override; 
protected:
private:
};

#endif // CC_SYSTEM_H
