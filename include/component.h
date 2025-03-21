#ifndef COMPONENT_H
#define COMPONENT_H

class Component {
public:
	virtual ~Component() = default; // Virtual destructor for polymorphic behaviour
	virtual void activate() = 0;
protected:
private:
};

#endif // COMPONENT_H
