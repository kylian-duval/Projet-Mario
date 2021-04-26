#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "jeu.h"
#include "editeur.h"
#include "constantes.h"


int main(int argc, char **argv)
{
	sf::Window window(sf::VideoMode(800, 600), "My window");

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée

	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			

			sf::Text text;

			

			// choix de la chaîne de caractères à afficher
			text.setString("Hello world");

			// choix de la taille des caractères
			text.setCharacterSize(24); // exprimée en pixels, pas en points !

			// choix de la couleur du texte
			text.setFillColor(sf::Color::Red);

			// choix du style du texte
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);

			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}