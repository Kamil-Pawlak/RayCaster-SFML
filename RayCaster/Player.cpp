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

void Player::update(sf::Time deltaTime)
{
	
}

void Player::rotate(float angle, sf::Time deltaTime)
{
	this->angle += angle;
	this->angle = fmod(this->angle, 360);
	shape.setRotation(this->angle);
	//std::cout << this->angle << std::endl;
}

void Player::move(float x, float y, sf::Time deltaTime)
{
	//rotate the moving vector by the angle and move
	float dx = x * cos(angle * 3.14159265 / 180) - y * sin(angle * 3.14159265 / 180);
	float dy = x * sin(angle * 3.14159265 / 180) + y * cos(angle * 3.14159265 / 180);
	shape.move(100.f * dx * deltaTime.asSeconds(), 100.f * dy * deltaTime.asSeconds());
}


void Player::draw(sf::RenderWindow& window)
{
	window.draw(shape);
}

