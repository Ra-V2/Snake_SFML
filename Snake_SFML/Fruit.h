#pragma once
#include "SFML/Graphics.hpp"
#include "Snake.h"

class Fruit
{
	friend class Snake;

private:

	sf::RectangleShape fruit;
	sf::Vector2f fruitPosition;

public:

	Fruit(const Snake & snake);
	void SpawnFruit(const Snake & snake);

	inline sf::RectangleShape GetFruit() { return fruit; }
};
