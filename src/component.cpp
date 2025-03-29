#include "../include/component.h"

void Component::register_function(const std::string& f_name, const std::function<void(const std::string& args)>& func) 
{
    _registered_functions[f_name] = func;
}

void Component::use_function(const std::string& f_name, const std::string& args)
{
    auto it = _registered_functions.find(f_name);
    if(it != _registered_functions.end()) {
        try {
            it->second(args);
        } catch (const std::exception& e) {
            std::cerr << "Error invoking function '" << f_name << "': " << e.what() << std::endl;
        }
    } else {
        std::cerr << "Function " << f_name << " is not registered." << std::endl;
    }
}
