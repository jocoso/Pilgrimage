#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <string>
#include <map>
#include <functional>

class Component {
public:
	virtual ~Component() = default; // Virtual destructor for polymorphic behaviour
	virtual void activate() = 0;
	void use_function(const std::string& f_name, const std::string& args);
	protected:
		void register_function(const std::string& f_name, const std::function<void(const std::string& args)>& func);
	private:
	std::map<std::string, std::function<void(const std::string&)>> _registered_functions;
};

#endif // COMPONENT_H
