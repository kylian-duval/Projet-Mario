#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>


int main()
{
	//varioble-------------------------------------------------------------------------------------------------------------
	int vitesseMario = 2; //récler le vitesse de déplacement de Mario
	int menu = 0;
	int TailleFenetteAuteur = 408; // reglage de la auteur de la  fennetre du jeu pas du menu
	int TailleFenetteLargeur= 408; // reglage de la auteur de la  fennetre du jeu pas du menu
	//----------------------------------------------------------------------------------------------------------------
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(TailleFenetteAuteur, TailleFenetteLargeur), "SFML window");
	window.setFramerateLimit(60);
	sf::Texture Mur;
	sf::Texture Mario;
	sf::Sprite sprite_Mario;
	sf::Texture sol;
	sf::Texture objectif;
	
	
	
	if (!Mario.loadFromFile("image/mario_bas.gif")) {
		printf("imposible de charger mario bas");
	}
	sprite_Mario.setTexture(Mario);
	if (!sol.loadFromFile("image/herbe.jpg")) {
		printf("impossible de charger le sol");
	}
	if (!objectif.loadFromFile("image/objectif.png")) {
		printf("impossible de charger l'objectif");
	}
	if (!Mur.loadFromFile("image/mur.jpg")) {
		printf("imposible de charger le mur");
	}


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
			#include "map.h";
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
			sprite.setPosition(0,0);
			

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