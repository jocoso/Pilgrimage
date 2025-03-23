
#ifndef IO_COMPONENT_H
#define IO_COMPONENT_H

#include "./component.h"
#include <iostream>
#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class IOComponent : public Component {
public:
	IOComponent(unsigned int width, unsigned int height, const std::string& title);
	IOComponent(const IOComponent& other);
	void activate() override;
protected:
	std::unique_ptr<sf::VideoMode> _size;
	std::string _title;
private:
};

#endif // IO_COMPONENT_H
