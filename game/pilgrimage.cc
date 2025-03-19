#include <vector>
#include <memory>
#include <iostream>

#include "../src/system.cpp"

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

class FlyingSystem : public System {
public:
	void run() override {
		std::cout << "FLYING_SYSTEM:UNSTARTED." << std::endl;
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

class Component {
public:
	virtual ~Component() = default; // Virtual destructor for polymorphic behaviour
protected:
private:
};

class IOComponent : public Component {
public:
protected:
private:
};

class RandomizerComponent : public Component {
public:
protected:
private:
};

class Brain {
public:
    Brain(std::vector<std::unique_ptr<System>>&& systems, std::vector<std::unique_ptr<Component>>&& components) : _systems(std::move(systems)), _components(std::move(components)) {
        
    }
    
    void wake() {
    	// For each System object in _system...
    	for (const auto& system : _systems) {
    		system->run();
    	}
    }
protected:
private:
    std::vector<std::unique_ptr<System>> _systems;
    std::vector<std::unique_ptr<Component>> _components;
};

int main() 
{
    std::vector<std::unique_ptr<System>> systems;
    systems.push_back(make_unique<DialogueSystem>());
    systems.push_back(make_unique<FightingSystem>());
    systems.push_back(make_unique<InventorySystem>());
    systems.push_back(make_unique<FlyingSystem>());
    systems.push_back(make_unique<EconomicSystem>());
    systems.push_back(make_unique<CraftingSystem>());
    systems.push_back(make_unique<GovernmentSystem>());
    
    std::vector<std::unique_ptr<Component>> components;
    components.push_back(make_unique<IOComponent>());
    components.push_back(make_unique<RandomizerComponent>());

    Brain brain(std::move(systems), std::move(components));
    brain.wake();
    
    return 0;
}

