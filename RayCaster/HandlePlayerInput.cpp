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
	//looking with mouse
	
}