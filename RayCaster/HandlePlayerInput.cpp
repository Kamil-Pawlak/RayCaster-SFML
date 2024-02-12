#include "Game.h"

//handle player input method
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::A)
		left = isPressed;
	else if (key == sf::Keyboard::D)
		right = isPressed;
	else if (key == sf::Keyboard::W)
		up = isPressed;
	else if (key == sf::Keyboard::S)
		down = isPressed;
	else if(key == sf::Keyboard::Left)
		lookL = isPressed;
	else if (key == sf::Keyboard::Right)
		lookR = isPressed;
}
void Game::handleMouseMovement()
{
	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2i mouseDelta = mousePos - prevMousePos;
	player.rotate(mouseDelta.x * 0.1, TimePerFrame);
	sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2), window);
	prevMousePos = sf::Mouse::getPosition(window);
}
