#include "Game.h"

//render method
void Game::render()
{
	window.clear();
	map.drawMap(window);
	player.draw(window);
	//draw floor
	
	sf::RectangleShape floor;
	floor.setSize(sf::Vector2f(window.getSize().x, window.getSize().y / 2));
	floor.setPosition(0, window.getSize().y / 2);
	floor.setFillColor(sf::Color(100, 100, 100));
	window.draw(floor);
	//draw ceiling
	sf::RectangleShape ceiling;
	ceiling.setSize(sf::Vector2f(window.getSize().x, window.getSize().y / 2));
	ceiling.setPosition(0, 0);
	ceiling.setFillColor(sf::Color(50, 50, 50));
	window.draw(ceiling);
	//draw walls
	player.castRays(window, map);
	
	
	window.display();
}

