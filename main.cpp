#include <SFML/Graphics.hpp>
//page de test
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

int main()
{
	//varioble-------------------------------------------------------------------------------------------------------------
	int vitesseMario = 2; //récler le vitesse de déplacement de Mario
	int menu = 0;
	//----------------------------------------------------------------------------------------------------------------
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
	window.setFramerateLimit(60);
	sf::Texture Mario;
	sf::Sprite sprite_Mario;
	
	if (!Mario.loadFromFile("image/mario_bas.gif")) {
		printf("imposible de charger mario bas");
	}
	sprite_Mario.setTexture(Mario);
	
	
	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (menu == 1)
		{
			#include "jeu.h";
			// Clear screen
			window.clear();
			// Draw the sprite
			window.draw(sprite_Mario);
			// Update the window
			window.display();
		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();
		// Draw the sprite
		window.draw(sprite_Mario);
		// Update the window
		window.display();

		while (menu == 0) {
			sf::Texture texture;
			if (!texture.loadFromFile("image/menu.jpg"))
			{
				return EXIT_FAILURE;
			}

			sf::Sprite sprite(texture);
			sprite.setPosition(150, 75);
			//sprite.setTextureRect(sf::IntRect(0, 0, 300, 300));
			window.setSize(sf::Vector2u(500, 500));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
			{
				menu = 1;
			}
		
			window.clear();
			// Draw the sprite
			window.draw(sprite);
			// Update the window
			window.display();

		}

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

}