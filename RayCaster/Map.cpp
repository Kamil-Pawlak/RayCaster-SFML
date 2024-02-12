#include "Map.h"
#include <fstream>
#include <iostream>

Map::Map()
{
	wall.setFillColor(sf::Color::Blue);
}

void Map::loadMap(std::string fileName, sf::RenderWindow &window)
{
	std::ifstream input;
	input.open(fileName);
	if (!input.is_open())
	{
		std::cout << "Could not load map file!" << std::endl;
		return;
	}
	char ch;
	int i = 0;
	int j = 0;
	input >> sizeX;
	input >> sizeY;
	//set size of the map
	map.resize(sizeX);
	for (int i = 0; i < sizeX; i++)
		map[i].resize(sizeY);
	while (input.get(ch))
	{
		//load map to vector of vectors from file
		//map file looks like this:
		// 50 - x size
		// 50 - y size
		//11111111111111111111
		//10000001000000000001
		//10000001000000000001
		//... 0 - empty space
		// 1 - wall
		if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4')
		{
			map[i][j] = ch - '0';
			i++;
			if (i == sizeX)
			{
				i = 0;
				j++;
			}
		}
	}
	input.close();
	//set size of the walls based on size of map and size of window
	sf::Vector2f wallSize;
	wallSize.x = window.getSize().x / sizeX;
	wallSize.y = window.getSize().y / sizeY;
	wall.setSize(wallSize);
}

void Map::printMap()
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			std::cout << map[i][j];
		}
		std::cout << std::endl;
	}
}

void Map::drawMap(sf::RenderWindow& window)
{
	//draw walls
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (map[i][j] == 1)
			{
				wall.setPosition(i * wall.getSize().x, j * wall.getSize().y);
				window.draw(wall);
			}
		}
	}
}