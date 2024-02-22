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
	void castRays(sf::RenderWindow &window, Map &map);
	sf::Vector2f getPos() { return pos; }
	void spawn(Map map);

private:
	sf::CircleShape shape;
	float angle;
	sf::Vector2f pos;
	sf::Vector2f dir;
	sf::Vector2f plane;
	int fov = 90;

};

