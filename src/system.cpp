#include "../include/system.h"

void System::assign_component(const std::string& component_name, std::shared_ptr<Component> component) {
	_components[component_name] = component;
}
