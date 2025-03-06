#pragma once
#include "Framework/GameObject.h"
#include "Framework/VectorHelper.h"

class Ball : public GameObject
{
public:
	Ball();
	Ball(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f dir, float speed);
	void handleInput(float dt) override;
	void update(float dt) override;
	void setDirection(sf::Vector2f dir);

protected:
	sf::Vector2f direction = sf::Vector2f(0, 0);
	float speed = 10;
};

