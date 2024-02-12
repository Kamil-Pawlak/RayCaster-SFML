#include "Game.h"

//update method
void Game::update(sf::Time deltaTime)
{
	//player movement
	if (up)
	{
		player.move(0.f, -1.f, deltaTime, map);
	}
	if (down)
	{
		player.move(0.f, 1.f, deltaTime, map);
	}
	if (left)
	{
		player.move(-1.f, 0.f, deltaTime, map);
	}
	if (right)
	{
		player.move(1.f, 0.f, deltaTime, map);
	}
	if (lookR)
	{
		player.rotate(2.5f, deltaTime);
	}
	if (lookL)
	{
		player.rotate(-2.5f, deltaTime);
	}
}