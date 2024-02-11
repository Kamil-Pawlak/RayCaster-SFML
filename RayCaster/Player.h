#pragma once
#include "SFML/Graphics.hpp"
#include "Map.h"

class Player {
public:
	Player();
	void update(sf::Time deltaTime, Map &map);
	void rotate(float angle, sf::Time deltaTime);
	void move(float x, float y, sf::Time deltaTime, Map &map);
	void draw(sf::RenderWindow& window);
	

private:
	sf::CircleShape shape;
	float angle;
};
