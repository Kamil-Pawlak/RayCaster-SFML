#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

class Map
{
public:
	Map();
	void loadMap(std::string filename, sf::RenderWindow &window);
	void printMap();
	void drawMap(sf::RenderWindow& window);
	std::vector<std::vector<int>> getMap() { return map; }
	sf::RectangleShape getWall() { return wall; }
	sf::Vector2i getWallSize() { return sf::Vector2i(wall.getSize().x, wall.getSize().y); }
	sf::Vector2f getTile(float x, float y) { return sf::Vector2f(x / sizeX, y / sizeY); }
	int getWidth() { return sizeX; }
	int getHeight() { return sizeY; }


private:
	int sizeX = 0;
	int sizeY = 0;
	std::vector<std::vector<int>> map;
	sf::RectangleShape wall;
};
