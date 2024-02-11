#include "Game.h"

//render method
void Game::render()
{
	window.clear();
	map.drawMap(window);
	player.draw(window);
	window.display();
}