
#ifndef IO_COMPONENT_H
#define IO_COMPONENT_H

#include <iostream>
#include "./component.h"

class IOComponent : public Component {
public:
	void activate() override;
protected:
private:
};

#endif // IO_COMPONENT_H
