#pragma once
#include "SFML/Graphics.hpp"

class Player {
public:
	Player();
	void update(sf::Time deltaTime);
	void rotate(float angle, sf::Time deltaTime);
	void move(float x, float y, sf::Time deltaTime);
	void draw(sf::RenderWindow& window);

private:
	sf::CircleShape shape;
	float angle;
};
