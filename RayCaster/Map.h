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
	
private:
	int sizeX = 0;
	int sizeY = 0;
	std::vector<std::vector<int>> map;
	sf::RectangleShape wall;
};
