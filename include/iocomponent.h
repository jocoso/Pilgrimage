
#ifndef IO_COMPONENT_H
#define IO_COMPONENT_H

#include "./component.h"
#include <iostream>
#include <memory>
#include <deque>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class IOComponent : public Component {
public:
	IOComponent(unsigned int width, unsigned int height, const int max_logs_displayed, const std::string& title);
	IOComponent(const IOComponent& other);
	void write(const std::string input);
	const std::deque<std::string>& get_log() const;
	void activate() override;
protected:
	std::unique_ptr<sf::VideoMode> _size;
	std::string _title;
	std::deque<std::string> _log;
	const int _MAX_LOGS_DISPLAYED;
private:
};

#endif // IO_COMPONENT_H
