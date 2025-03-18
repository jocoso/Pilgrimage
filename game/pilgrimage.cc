#include <vector>
#include <memory>

class System
{
public:
	virtual ~System() = default; // Virtual destructor for polymorphic behaviour
protected:
private:
};

class DialogueSystem : public System {
public:
protected:
private:
};

class FightingSystem : public System {
public:
protected:
private:
};

class InventorySystem : public System {
public:
protected:
private:
};

class FlyingSystem : public System {
public:
protected:
private:
};

class EconomicSystem : public System {
public:
protected:
private:
};

class CraftingSystem : public System {
public:
protected:
private:
};

class GovernmentSystem : public System {
public:
protected:
private:
};

class Brain {
public:
    Brain(std::vector<std::unique_ptr<System>>&& systems) : _systems(std::move(systems)) {
        
    }
protected:
private:
    std::vector<std::unique_ptr<System>> _systems;
};

int main() 
{
    std::vector<std::unique_ptr<System>> systems;
    systems.push_back(std::make_unique<DialogueSystem>());
    systems.push_back(std::make_unique<FightingSystem>());
    systems.push_back(std::make_unique<InventorySystem>());
    systems.push_back(std::make_unique<FlyingSystem>());
    systems.push_back(std::make_unique<EconomicSystem>());
    systems.push_back(std::make_unique<CraftingSystem>());
    systems.push_back(std::make_unique<GovernmentSystem>());

    Brain brain(std::move(systems));
    
    return 0;
}

