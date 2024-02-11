#include "Game.h"

//render method
void Game::render()
{
	window.clear();
	player.draw(window);
	window.display();
}