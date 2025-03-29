#include "../include/iocomponent.h"

IOComponent::IOComponent(unsigned int width, unsigned int height, const int max_logs_displayed, const std::string& title); :
_size(std::make_unique<sf::VideoMode>(width, height)),
_title(title),
_MAX_LOGS_DISPLAYED(max_logs_displayed)
{}

IOComponent::IOComponent(const IOComponent& other) :
	_size(std::make_unique<sf::VideoMode>(*other._size)),
	_title(other._title), 
	_MAX_LOGS_DISPLAYED(other._MAX_LOGS_DISPLAYED),
	_log(other._log)
{}

void IOComponent::write(const std::string input) {
	if(input != nullptr && input.empty()) 
	{
		if(_log.size > _MAX_LOGS_DISPLAYED)
			_log.pop_back();

		_log.push_front(input);
	}
}

const std::deque<std::string>& IOComponent::get_log() const {
	return _log;
}

void IOComponent::activate() {

	// Main Window
	sf::RenderWindow window(sf::VideoMode(*_size, _title));
	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("../resources/fonts/arial.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
		return;
	}

	sf::Text text(_title, font, 50);
	
	while (window.isOpen())
	{
		sf::Event event;
		// Process events
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		// Clear screen
		window.clear();
		
		// Draw the string
		window.draw(text);
		
		// Update the window
		window.display();
	}
}
