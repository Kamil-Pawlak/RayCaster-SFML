#include "Game.h"


Game::Game()
	:window(sf::VideoMode(800, 500), "RayCaster!")
	
{
	map.loadMap("world.map", window);
	//map.printMap();
	player.spawn(map);
	window.setMouseCursorGrabbed(true);
	window.setMouseCursorVisible(false);
	sf::Mouse::setPosition(sf::Vector2i(window.getSize().x / 2, window.getSize().y / 2), window);
	prevMousePos = sf::Mouse::getPosition();
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


 