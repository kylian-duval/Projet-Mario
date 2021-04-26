#include <SFML/Graphics.hpp>

#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include "jeu.h"
#include "editeur.h"
#include "constantes.h"




int main(int argc, char **argv)
{
		sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

		// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e

		//----------------------------phase test ---------------------------
		sf::Texture texture;
		if (!texture.loadFromFile("image/menu.jpg"))
			return EXIT_FAILURE;
		sf::Texture texture2;
		if (!texture2.loadFromFile("image/mur.jpg"))
			return EXIT_FAILURE;
		sf::Sprite sprite(texture);
		//-------------------------------------------------------------------------

		while (window.isOpen())
		{
			// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
			sf::Event event;

			while (window.pollEvent(event))
			{

				// �v�nement "fermeture demand�e" : on ferme la fen�tre
				if (event.type == sf::Event::Closed)
					window.close();
			}

			//----------------------------------------------
			window.clear();
			window.draw(sprite);
			window.display();
			//---------------------------------------------------
		}
		return 0;
}
