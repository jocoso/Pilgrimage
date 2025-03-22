#ifndef CC_SYSTEM_H
#define CC_SYSTEM_H

#include <iostream>
#include "iocomponent.h"

class CharacterCreationSystem : public System {
public:
	void run() override;
	
protected:
private:
	IOComponent _window;
};

#endif // CC_SYSTEM_H
