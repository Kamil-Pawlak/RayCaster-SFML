#include "Game.h"

//processEvents method
void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{	
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
		break;
		
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
		break;
		
		case sf::Event::Closed:
			window.close();
		break;
				
		}
	}
}