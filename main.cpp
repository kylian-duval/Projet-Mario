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
	int rotationMario = 1;
	int rotationlougis = 1;
	//------------------------------------------------------------------------------------------------------------------------------
	sf::RenderWindow window(sf::VideoMode(TailleFenetteAuteur, TailleFenetteLargeur), "SFML window");
	window.setFramerateLimit(60);
	sf::Texture Mur;
	sf::Texture Mario;
	sf::Texture lougis;
	sf::Sprite sprite_Mario;
	sf::Sprite sprite_lougis;
	sf::Texture sol;
	sf::Texture objectif;
	sf::Texture caisse;
	sf::Sprite sprite_caisse;
	sf::SoundBuffer audio;
	sf::Sound Sounde_audio;


	
	
	
	
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

	if (!caisse.loadFromFile("image/caisse.jpg")) {
		printf("imposible de charger la cesse");
	}
	sprite_caisse.setTexture(caisse);

	if (!lougis.loadFromFile("image/lougis_bas.png")) {
		printf("imposible de charger louigi bas");
	}
	sprite_lougis.setTexture(lougis);
	

	while (window.isOpen())
	{

		// Process events
		sf::Event event;
		sprite_caisse.setPosition(102, 170);
		sprite_Mario.setPosition(34,170);
		
		
		while (menu == 1)
		{
		#include "jeu.cpp";



			window.clear();
			#include "map.cpp";
			window.draw(sprite_caisse);

			
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
				if (!audio.loadFromFile("Audio/drm64_mario5.wav"))
				{
					printf("inposiible de charger le fichier audio");
				}
				Sounde_audio.setBuffer(audio);
				Sounde_audio.play();
				menu = 1;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad2))
			{
				if (!audio.loadFromFile("Audio/drm64_mario5.wav"))
				{
					printf("inposiible de charger le fichier audio");
				}
				Sounde_audio.setBuffer(audio);
				Sounde_audio.play();
				menu = 3;
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
		while (menu == 2) {
			sf::Texture gg;
			if (!gg.loadFromFile("image/gg.jpg"))
			{
				return EXIT_FAILURE;
			}

			sf::Sprite sprite_gg(gg);
			sprite_gg.setPosition(0, 0);

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				menu = 3;
			}


			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1))
			{
				if (!audio.loadFromFile("Audio/drm64_mario5.wav"))
				{
					printf("imposible de charger le fichier audio");
				}
				Sounde_audio.setBuffer(audio);
				Sounde_audio.play();
				menu = 1;
			}

			window.clear();
			// Draw the sprite
			window.draw(sprite_gg);
			// Update the window
			window.display();
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

		}
		while (menu == 3)
		{
			#include "jeu.cpp";

			window.clear();

			window.draw(sprite_caisse);


			window.draw(sprite_Mario);
			window.draw(sprite_lougis);

			window.display();

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
		}
	}
}