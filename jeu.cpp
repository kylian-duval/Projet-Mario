
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	if (!Mario.loadFromFile("image/mario_haut.gif")) {
		printf("imposible de charger mario haut");
	}
	rotation = 2;
	sprite_Mario.move(0, -vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	if (!Mario.loadFromFile("image/mario_bas.gif")) {
		printf("imposible de charger mario bas");
	}
	rotation = 1;
	sprite_Mario.move(0, vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	if (!Mario.loadFromFile("image/mario_gauche.gif")) {
		printf("imposible de charger mario gauche");
	}
	rotation = 4;
	sprite_Mario.move(-vitesseMario, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	if (!Mario.loadFromFile("image/mario_droite.gif")) {
		printf("imposible de charger mario droite");
	}
	rotation = 3;
	sprite_Mario.move(vitesseMario, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
	if (!Mario.loadFromFile("image/mario_haut.gif")) {
		printf("imposible de charger mario haut");
	}
	rotation = 2;
	sprite_Mario.move(0, -vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	if (!Mario.loadFromFile("image/mario_bas.gif")) {
		printf("imposible de charger mario bas");
	}
	rotation = 1;
	sprite_Mario.move(0, vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
	if (!Mario.loadFromFile("image/mario_gauche.gif")) {
		printf("imposible de charger mario gauche");
	}
	rotation = 4;
	sprite_Mario.move(-vitesseMario, 0);
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	if (!Mario.loadFromFile("image/mario_droite.gif")) {
		printf("imposible de charger mario droite");
	}
	rotation = 3;
	sprite_Mario.move(vitesseMario, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
	menu = 0;
}
if (sprite_Mario.getPosition().x <= 0) {
	sprite_Mario.setPosition(sf::Vector2f(0, sprite_Mario.getPosition().y));
}
if (sprite_Mario.getPosition().y <= 0) {
	sprite_Mario.setPosition(sf::Vector2f(sprite_Mario.getPosition().x, 0));
}
if (sprite_Mario.getPosition().x >= TailleFenetteAuteur) {
	sprite_Mario.setPosition(sf::Vector2f(TailleFenetteAuteur-30, sprite_Mario.getPosition().y));
	
}
if (sprite_Mario.getPosition().y >= TailleFenetteLargeur) {
	sprite_Mario.setPosition(sf::Vector2f(sprite_Mario.getPosition().x, TailleFenetteLargeur-30));
	
}


if ((std::abs((sprite_Mario.getPosition().x + 17) - (sprite_caisse.getPosition().x + 17)) < 34) &&
(std::abs((sprite_Mario.getPosition().y + 17) - (sprite_caisse.getPosition().y + 17)) < 34))
{
	if (rotation == 1) {
		sprite_caisse.move(0, vitesseMario);
	}
	else if (rotation == 2) {
		sprite_caisse.move(0, -vitesseMario);
	}
	else if (rotation == 3) {
		sprite_caisse.move(vitesseMario, 0);
	}
	else if (rotation == 4) {
		sprite_caisse.move(-vitesseMario, 0);
	}

}