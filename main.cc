#include <vector>
#include <memory>
#include <iostream>
#include <map>

#include "../include/system.h"
#include "../include/component.h"
#include "../include/iocomponent.h"
#include "../include/ccsystem.h"

template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
	return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

class DialogueSystem : public System {
public:
	virtual ~DialogueSystem() = default;
	void run() override {
		std::cout << "DIALOGUE_SYSTEM:UNSTARTED." << std::endl;
	}
	
protected:
private:
};

class FightingSystem : public System {
public:
	void run() override {
		std::cout << "FIGHTING_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};

class InventorySystem : public System {
public:
	void run() override {
		std::cout << "INVENTORY_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};

class MagicSystem : public System {
public:
	void run() override {
		std::cout << "MAGIC_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};

class WeaponSystem : public System {
public:
	void run() override {
		std::cout << "WEAPON_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};


class EconomicSystem : public System {
public:
	void run() override {
		std::cout << "ECONOMIC_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};

class CraftingSystem : public System {
public:
	void run() override {
		std::cout << "CRAFTING_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};

class GovernmentSystem : public System {
public:
	void run() override {
		std::cout << "GOVERNMENT_SYSTEM:UNSTARTED." << std::endl;
	}
protected:
private:
};

class RandomizerComponent : public Component {
public:
	void activate() override {
		std::cout << "RANDOMIZER_COMPONENT:UNSTARTED." << std::endl;
	}
protected:
private:
};

class Brain {
public:
    Brain(std::vector<std::unique_ptr<System>>&& systems, std::map<std::string, std::unique_ptr<Component>>&& components) : _systems(std::move(systems)), _components(std::move(components)) {
        
    }
    
    void wakeSystems() {
    	// For each System object in _system...
    	for (const auto& system : _systems) {
    		system->run();
    	}
    }
    
    void activateComponent(const std::string& componentName) {
    	auto it = _components.find(componentName);
    	if (it != _components.end()) {
    		it->second->activate();
    	} else {
    		std::cout << "Component '" << componentName << "' not found." << std::endl;
    	}
    }
protected:
private:
    std::vector<std::unique_ptr<System>> _systems;
    std::map<std::string, std::unique_ptr<Component>> _components;
};

int main() 
{
    std::vector<std::unique_ptr<System>> systems;
    systems.push_back(make_unique<DialogueSystem>());
    systems.push_back(make_unique<FightingSystem>());
    systems.push_back(make_unique<InventorySystem>());
    systems.push_back(make_unique<MagicSystem>());
    systems.push_back(make_unique<WeaponSystem>());
    systems.push_back(make_unique<EconomicSystem>());
    systems.push_back(make_unique<CraftingSystem>());
    systems.push_back(make_unique<GovernmentSystem>());
    //systems.push_back(make_unique<CharacterCreationSystem>());
    
    std::map<std::string, std::unique_ptr<Component>> components;
    components["io"] = make_unique<IOComponent>();
    components["randomizer"] = make_unique<RandomizerComponent>();

    Brain brain(std::move(systems), std::move(components));
    brain.wakeSystems();
    brain.activateComponent("io");
    brain.activateComponent("randomizer");
    
    return 0;
}

