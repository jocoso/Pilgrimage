#include "../include/iocomponent.h"

void IOComponent::activate() {

	// Main Window
	sf::RenderWindow window(sf::VideoMode({800, 600}), "Pilgrimage");
	// Create a graphical text to display
	sf::Font font;
	if (!font.loadFromFile("../resources/fonts/arial.ttf")) {
		std::cerr << "Failed to load font." << std::endl;
		return;
	}

	sf::Text text("Pilgrimage", font, 50);
	
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
	
	std::cout << "IO_COMPONENT:10%" << std::endl;
}
