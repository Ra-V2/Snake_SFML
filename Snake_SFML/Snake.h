#pragma once
#include "SFML/Graphics.hpp"
#include "Fruit.h"
#include <vector>

enum class direction { STOP, UP, DOWN, LEFT, RIGHT };

class Snake
{
	friend class Fruit;

private:
	int length;
	direction sdir;
	std::vector<sf::RectangleShape> shape;
	std::vector<sf::Vector2f> shapePosition;

public:
	Snake();
	void Control(sf::RenderWindow & window);
	void Growth();

	const bool CollisionFruit(const Fruit & fruit);
	const bool CollisionWall();
	const bool CollisionSnake();

	inline std::vector<sf::RectangleShape> GetShape() { return shape; }
	inline direction GetSdir() { return sdir; }
	inline int GetLength() { return length; }

	inline void SetDirection(direction dir) { sdir = dir; }

};