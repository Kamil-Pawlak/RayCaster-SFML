#include "Game.h"


Game::Game()
	:window(sf::VideoMode(800, 600), "RayCaster!")
{
	map.loadMap("world.map", window);
	//map.printMap();
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


 