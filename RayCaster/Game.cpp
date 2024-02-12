#include "Game.h"


Game::Game()
	:window(sf::VideoMode(1920, 1080), "RayCaster!",sf::Style::Fullscreen)
	
{
	map.loadMap("world.map", window);
	//map.printMap();
	//window.setMouseCursorGrabbed(true);
	//window.setMouseCursorVisible(false);
}

//run method
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}


 