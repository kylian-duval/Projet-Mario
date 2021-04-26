#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <stdio.h>

#include "jeu.h"
#include "editeur.h"
#include "constantes.h"


int main(int argc, char **argv)
{
	sf::Window window(sf::VideoMode(800, 600), "My window");

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e

	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event))
		{
			

			sf::Text text;

			

			// choix de la cha�ne de caract�res � afficher
			text.setString("Hello world");

			// choix de la taille des caract�res
			text.setCharacterSize(24); // exprim�e en pixels, pas en points !

			// choix de la couleur du texte
			text.setFillColor(sf::Color::Red);

			// choix du style du texte
			text.setStyle(sf::Text::Bold | sf::Text::Underlined);

			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}