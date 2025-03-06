#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	manager = BallManager();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	manager.handleInput(dt, input);
}

// Update game objects
void Level::update(float dt)
{
	manager.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	manager.render(window);
	endDraw();
}
