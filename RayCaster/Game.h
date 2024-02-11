#pragma once
#include "SFML/Graphics.hpp"
#include "ResourceHolder.h"
#include "Player.h"
#include "Map.h"

namespace Textures
{
	
}

//create game class
class Game
{
public:
	Game();
	void run();
	
private:
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time deltaTime);
	void render();
	void processEvents();
	bool left = 0, right = 0, up = 0, down = 0;
	bool lookR = 0, lookL = 0;
	//time per frame
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

private:
	//create window
	sf::RenderWindow window;
	Player player;
	Map map;
	
};

