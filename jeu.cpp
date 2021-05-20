
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	if (!Mario.loadFromFile("image/mario_haut.gif")) {
		printf("imposible de charger mario haut");
	}
	rotationMario = 2;
	sprite_Mario.move(0, -vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
	if (!Mario.loadFromFile("image/mario_bas.gif")) {
		printf("imposible de charger mario bas");
		printf("%d", sprite_Mario.getPosition().x);
	}
	rotationMario = 1;
	sprite_Mario.move(0, vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	if (!Mario.loadFromFile("image/mario_gauche.gif")) {
		printf("imposible de charger lougis gauche");
	}
	rotationMario = 4;
	sprite_Mario.move(-vitesseMario, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	if (!Mario.loadFromFile("image/mario_droite.gif")) {
		printf("imposible de charger lougis droite");
	}
	rotationMario = 3;
	sprite_Mario.move(vitesseMario, 0);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
	if (!lougis.loadFromFile("image/lougis_haut.png")) {
		printf("imposible de charger lougis haut");
	}
	rotationlougis = 2;
	sprite_lougis.move(0, -vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
	if (!lougis.loadFromFile("image/lougis_bas.png")) {
		printf("imposible de charger lougis bas");
	}
	rotationlougis = 1;
	sprite_lougis.move(0, vitesseMario);
}
if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
	if (!lougis.loadFromFile("image/lougis_gauche.png")) {
		printf("imposible de charger lougis gauche");
	}
	rotationlougis = 4;
	sprite_lougis.move(-vitesseMario, 0);
}
else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
	if (!lougis.loadFromFile("image/lougis_droite.png")) {
		printf("imposible de charger mario droite");
	}
	rotationlougis = 3;
	sprite_lougis.move(vitesseMario, 0);
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

if (sprite_Mario.getPosition().x > 374)
{
	sprite_Mario.setPosition(sf::Vector2f(374, sprite_Mario.getPosition().y));
}

if (sprite_Mario.getPosition().y > 374)
{
	sprite_Mario.setPosition(sf::Vector2f(sprite_Mario.getPosition().x, 374));
}




if (sprite_lougis.getPosition().x <= 0) {
	sprite_lougis.setPosition(sf::Vector2f(0, sprite_lougis.getPosition().y));
}
if (sprite_lougis.getPosition().y <= 0) {
	sprite_lougis.setPosition(sf::Vector2f(sprite_lougis.getPosition().x, 0));
}

if (sprite_lougis.getPosition().x > 374)
{
	sprite_lougis.setPosition(sf::Vector2f(374, sprite_lougis.getPosition().y));
}

if (sprite_lougis.getPosition().y > 374)
{
	sprite_lougis.setPosition(sf::Vector2f(sprite_lougis.getPosition().x, 374));
}



if (sprite_caisse.getPosition().x <= 0) {
	sprite_caisse.setPosition(sf::Vector2f(0, sprite_caisse.getPosition().y));
}
if (sprite_caisse.getPosition().y <= 0) {
	sprite_caisse.setPosition(sf::Vector2f(sprite_caisse.getPosition().x, 0));
}


if (sprite_caisse.getPosition().x > 374)
{
	sprite_caisse.setPosition(sf::Vector2f(374, sprite_caisse.getPosition().y));
}

if (sprite_caisse.getPosition().y > 374)
{
	sprite_caisse.setPosition(sf::Vector2f(sprite_caisse.getPosition().x, 374));
}



if ((std::abs((sprite_Mario.getPosition().x + 17) - (sprite_caisse.getPosition().x + 17)) < 34) &&
(std::abs((sprite_Mario.getPosition().y + 17) - (sprite_caisse.getPosition().y + 17)) < 34))
{
	if (rotationMario == 1) {
		sprite_caisse.move(0, vitesseMario);
	}
	else if (rotationMario == 2) {
		sprite_caisse.move(0, -vitesseMario);
	}
	else if (rotationMario == 3) {
		sprite_caisse.move(vitesseMario, 0);
	}
	else if (rotationMario == 4) {
		sprite_caisse.move(-vitesseMario, 0);
	}

}


if ((std::abs((sprite_lougis.getPosition().x + 17) - (sprite_caisse.getPosition().x + 17)) < 34) &&
(std::abs((sprite_lougis.getPosition().y + 17) - (sprite_caisse.getPosition().y + 17)) < 34))
{
	if (rotationlougis == 1) {
		sprite_caisse.move(0, vitesseMario);
	}
	else if (rotationlougis == 2) {
		sprite_caisse.move(0, -vitesseMario);
	}
	else if (rotationlougis == 3) {
		sprite_caisse.move(vitesseMario, 0);
	}
	else if (rotationlougis == 4) {
		sprite_caisse.move(-vitesseMario, 0);
	}

}