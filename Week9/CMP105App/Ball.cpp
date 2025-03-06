#include "Ball.h"

Ball::Ball()
{
}

Ball::Ball(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f dir, float speed)
{
	setPosition(pos);
	setSize(size);
	direction = dir;
	this->speed = speed;
}

void Ball::handleInput(float dt)
{
}

void Ball::update(float dt)
{
	move(VectorHelper::normalise(direction) * speed * dt);
}

void Ball::setDirection(sf::Vector2f dir)
{
	direction = dir;
}
