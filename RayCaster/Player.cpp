#include "Player.h"
#include <iostream>

Player::Player()
{
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(15.f);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setPosition(100.f, 100.f);
	angle = 0;
}

void Player::update(sf::Time deltaTime, Map &map)
{
	
}


void Player::rotate(float angle, sf::Time deltaTime)
{
	//apply delta time to angle of rotation
	angle *= deltaTime.asMilliseconds()/4;
	this->angle += angle;
	this->angle = fmod(this->angle, 360);
	shape.setRotation(this->angle);
	//std::cout << this->angle << std::endl;
}

void Player::move(float x, float y, sf::Time deltaTime, Map &map)
{
	//apply deltatime to x and y
	y *= deltaTime.asMilliseconds()/4;
	x *= deltaTime.asMilliseconds()/4;
	
	//rotate the moving vector by the angle and move
	float dx = (x * cos(angle * 3.14159265 / 180) - y * sin(angle * 3.14159265 / 180));
	float dy = (x * sin(angle * 3.14159265 / 180) + y * cos(angle * 3.14159265 / 180));
	//check for collisions and remove colliding coordinate out of vector
	//adjust collisions for size of a player
	// Define the offsets for checking adjacent tiles
	const float offsetX[4] = { 15.f, 15.f, -15.f, -15.f };
	const float offsetY[4] = { 15.f, -15.f, 15.f, -15.f };

	// Get the position of the shape
	sf::Vector2f shapePosition = shape.getPosition();
	float wallSizeX = map.getWall().getSize().x;
	float wallSizeY = map.getWall().getSize().y;

	// Check if the shape can move in the x-direction
	bool canMoveX = true;
	for (int i = 0; i < 4; ++i) {
		int xIndex = (int)(shapePosition.x + dx + offsetX[i]) / wallSizeX;
		int yIndex = (int)(shapePosition.y + offsetY[i]) / wallSizeY;
		if (map.getMap()[xIndex][yIndex] != 0) {
			canMoveX = false;
			break;
		}
	}
	if (canMoveX)
		shape.move(dx, 0);

	// Check if the shape can move in the y-direction
	bool canMoveY = true;
	for (int i = 0; i < 4; ++i) {
		int xIndex = (int)(shapePosition.x + offsetX[i]) / wallSizeX;
		int yIndex = (int)(shapePosition.y + dy + offsetY[i]) / wallSizeY;
		if (map.getMap()[xIndex][yIndex] != 0) {
			canMoveY = false;
			break;
		}
	}
	if (canMoveY)
		shape.move(0, dy);
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

