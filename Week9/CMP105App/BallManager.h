#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "Ball.h"
#include <iostream>
#include "Framework/Input.h"

class BallManager
{
public:
	BallManager();
	void handleInput(float dt, Input* input);
	void update(float dt);
	void render(sf::RenderWindow* window);

protected:
	Ball balls[20];
};

