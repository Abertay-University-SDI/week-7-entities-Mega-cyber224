#include "BallManager.h"

BallManager::BallManager()
{
	srand(time(0));
	static sf::Texture ballTexture;
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		balls[i] = Ball(sf::Vector2f(300, 300), sf::Vector2f(50, 50), sf::Vector2f(((rand() % 200) - 100) / 100.f, ((rand() % 200) - 100) / 100.f), 100);
		balls[i].setTexture(&ballTexture);
		balls[i].setOrigin(sf::Vector2f(25, 25));
	}
}

void BallManager::handleInput(float dt, Input* input)
{
	if (input->isLeftMousePressed())
	{
		for (int i = 0; i < 20; i++)
		{
			if (!balls[i].isAlive())
			{
				balls[i].setAlive(true);
				balls[i].setPosition(sf::Vector2f(input->getMouseX(), input->getMouseY()));
				balls[i].setDirection(sf::Vector2f(((rand() % 200) - 100) / 100.f, ((rand() % 200) - 100) / 100.f));
			}
		}
	}
}

void BallManager::update(float dt)
{
	for (int i = 0; i < 20; i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
			if (balls[i].getPosition().x > 700)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().x < -50)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y > 700)
			{
				balls[i].setAlive(false);
			}
			if (balls[i].getPosition().y < -50)
			{
				balls[i].setAlive(false);
			}
		}
	}
}

void BallManager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < 20; i++)
	{
		if (balls[i].isAlive())
		{
			window->draw(balls[i]);
		}
	}
}
