#ifndef SYSTEM_H
#define SYSTEM_H

#include "component.h"

#include <string>
#include <memory>
#include <map>

class System
{
public:
	virtual ~System() = default;  // Ensure virtual destructor
	virtual void run() = 0; 
	void assign_component(const std::string& component_name, std::shared_ptr<Component> component);
protected:
	std::map<std::string, std::shared_ptr<Component>> _components;
private:
};

#endif // SYSTEM_H
