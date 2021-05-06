#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>


int main()
{
	//varioble-------------------------------------------------------------------------------------------------------------
	int vitesseMario = 2; //récler le vitesse de déplacement de Mario
	int menu = 0;
	int TailleFenetteAuteur = 408; // reglage de la auteur de la  fennetre du jeu pas du menu
	int TailleFenetteLargeur= 408; // reglage de la auteur de la  fennetre du jeu pas du menu
	/*
	1 = mario haut
	2 = mario bas
	3 = mario gauche
	4 = mario droite
	*/
	int rotation = 1;
	//----------------------------------------------------------------------------------------------------------------
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(TailleFenetteAuteur, TailleFenetteLargeur), "SFML window");
	window.setFramerateLimit(60);
	sf::Texture Mur;
	sf::Texture Mario;
	sf::Sprite sprite_Mario;
	sf::Texture sol;
	sf::Texture objectif;
	sf::Texture cesse;
	sf::Sprite sprite_cesse;
	
	
	
	if (!Mario.loadFromFile("image/mario_bas.gif")) {
		printf("imposible de charger mario bas");
	}
	sprite_Mario.setTexture(Mario);
	if (!sol.loadFromFile("image/herbe.jpg")) {
		printf("impossible de charger le sol");
	}
	if (!objectif.loadFromFile("image/canabis.png")) {
		printf("impossible de charger l'objectif");
	}
	if (!Mur.loadFromFile("image/mur.jpg")) {
		printf("imposible de charger le mur");
	}

	if (!cesse.loadFromFile("image/caisse.jpg")) {
		printf("imposible de charger la cesse");
	}
	sprite_cesse.setTexture(cesse);
	sprite_cesse.setPosition(sf::Vector2f(68, 68));

	while (window.isOpen())
	{

		// Process events
		sf::Event event;
		while (menu == 1)
		{
		#include "jeu.h";



			window.clear();
			#include "map.h";
			window.draw(sprite_cesse);
			window.draw(sprite_Mario);

			window.display();

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
		}


		while (menu == 0) {
			sf::Texture texture;
			if (!texture.loadFromFile("image/menu.jpg"))
			{
				return EXIT_FAILURE;
			}

			sf::Sprite sprite(texture);
			sprite.setPosition(0, 0);


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
			{
				menu = 1;
			}

			window.clear();
			// Draw the sprite
			window.draw(sprite);
			// Update the window
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		}
	}
}