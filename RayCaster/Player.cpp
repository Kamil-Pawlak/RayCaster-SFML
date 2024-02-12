#include "Player.h"
#include <iostream>

template <typename T>
constexpr const T& clamp(const T& value, const T& low, const T& high) {
	return std::max(low, std::min(value, high));
}

Player::Player()
{
	shape.setFillColor(sf::Color::Red);
	shape.setRadius(15.f);
	shape.setOrigin(shape.getRadius(), shape.getRadius());
	shape.setPosition(200.f, 100.f);
	angle = 0;
}

void Player::update(sf::Time deltaTime, Map &map)
{
	//update vectors needed for raycasting calculations
	pos.x = shape.getPosition().x;
	pos.y = shape.getPosition().y;

	// Calculate direction vector (normalized)
	dir.x = sin(angle * (3.14 / 180));
	dir.y = -cos(angle * (3.14 / 180));

	// Calculate plane vector perpendicular to the direction vector
	// Note: Assuming the camera is looking straight ahead (no roll or tilt)
	// This vector represents the "width" of the camera view
	plane.x = -dir.y * 0.66f;
	plane.y = dir.x * 0.66f;
}


void Player::rotate(float angle, sf::Time deltaTime)
{
	// Define a rotation speed (in degrees per second)
	float rotationSpeed = 180.0f; // Adjust this value to change rotation speed

	// Calculate the rotation for this frame based on the rotation speed and delta time
	float rotationThisFrame = rotationSpeed * deltaTime.asSeconds();

	// Apply the rotation to the player's angle
	this->angle += angle * rotationThisFrame;

	// Ensure the angle stays within the range [0, 360)
	this->angle = std::fmod(this->angle, 360.0f);

	// Set the rotation of the player's shape
	shape.setRotation(this->angle);
}

void Player::move(float x, float y, sf::Time deltaTime, Map &map)
{
	//apply deltatime to x and y
	y *= deltaTime.asMilliseconds();
	x *= deltaTime.asMilliseconds();
	
	//calculate dx and dy
	float dx = x * cos(angle * (3.14159265359 / 180)) - y * sin(angle * (3.14159265359 / 180));
	float dy = x * sin(angle * (3.14159265359 / 180)) + y * cos(angle * (3.14159265359 / 180));
	
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
	//draw line that indicates dir vector
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(pos.x, pos.y)),
		sf::Vertex(sf::Vector2f(pos.x + dir.x * 50, pos.y + dir.y * 50))
	};
	window.draw(line, 2, sf::Lines);
}

void Player::castRays(sf::RenderWindow& window, Map& map) {
    int w = window.getSize().x;
    sf::Vector2i wallSize = map.getWallSize();
    sf::Vector2u windowSize = window.getSize();
    int stepSize = 20;

    // Pre-calculate constants
    double invW = 1.0 / w;
    sf::Vector2f invWallSize(1.0 / wallSize.x, 1.0 / wallSize.y);

    // Pre-calculate wall colors
    std::vector<sf::Color> wallColors = {
        sf::Color::White,  // 0
        sf::Color::Red,    // 1
        sf::Color::Green,  // 2
        sf::Color::Blue,   // 3
        sf::Color::Yellow  // 4
    };

	std::vector<sf::RectangleShape> rectangles;

	for (int i = 0; i < w; i += stepSize) {
		int index = i * 2;
		double cameraX = 2 * i * invW - 1;
		double dirX = dir.x + plane.x * cameraX;
		double dirY = dir.y + plane.y * cameraX;

		// Initialize current position to the player's position
		sf::Vector2f rayPos = pos;

		double sideDistX;
		double sideDistY;

		double deltaDistX = std::abs(1 / dirX);
		double deltaDistY = std::abs(1 / dirY);
		double perpWallDist;
		int stepX, stepY;
		int side;
		bool hit = false;

		if (dirX < 0) {
			stepX = -1;
			sideDistX = (pos.x - rayPos.x) * deltaDistX;
		}
		else {
			stepX = 1;
			sideDistX = (rayPos.x + 1.0 - pos.x) * deltaDistX;
		}
		if (dirY < 0) {
			stepY = -1;
			sideDistY = (pos.y - rayPos.y) * deltaDistY;
		}
		else {
			stepY = 1;
			sideDistY = (rayPos.y + 1.0 - pos.y) * deltaDistY;
		}

		while (!hit) {
			if (sideDistX < sideDistY) {
				sideDistX += deltaDistX;
				rayPos.x += stepX * wallSize.x;
				side = 0;
			}
			else {
				sideDistY += deltaDistY;
				rayPos.y += stepY * wallSize.y;
				side = 1;
			}
			if (rayPos.x < 0 || rayPos.y < 0)
				break;
			if (map.getMap()[rayPos.x / wallSize.x][rayPos.y / wallSize.y] != 0)
				hit = true;
		}
		if (side == 0)
			perpWallDist = sideDistX - deltaDistX;
		else
			perpWallDist = sideDistY - deltaDistY;
		int lineHeight = (windowSize.y / perpWallDist);
		int drawStart = -lineHeight / 2 + windowSize.y / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + windowSize.y / 2;
		if (drawEnd >= windowSize.y)
			drawEnd = windowSize.y - 1;
		sf::Color color = wallColors[map.getMap()[rayPos.x / wallSize.x][rayPos.y / wallSize.y]];

		if (side == 1) {
			color.r = std::max(0, color.r - 100);
			color.g = std::max(0, color.g - 100);
			color.b = std::max(0, color.b - 100);
		}
		
		// Create and position rectangles
		sf::RectangleShape rectangle(sf::Vector2f(stepSize, drawEnd - drawStart + 1));
		rectangle.setPosition(i, drawStart);
		rectangle.setFillColor(color);

		// Store rectangles in the vector
		rectangles.push_back(rectangle);
	}

	// Draw rectangles
	for (const auto& rect : rectangles) {
		window.draw(rect);
	}
}
        



	

	
