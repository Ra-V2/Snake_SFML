#pragma once
#include "SFML/Graphics.hpp"


enum class direction { STOP, UP, DOWN, LEFT, RIGHT };

class Snake
{
private:
	int length;
	float movePixels;
	direction sdir;
	sf::RectangleShape fruit;
	sf::Vector2f fruitPosition;
	sf::Vector2f shapeSize;
	std::vector<sf::RectangleShape> shape;
	std::vector<sf::Vector2f> shapePosition;

public:
	Snake();
	~Snake();
	void Control(sf::RenderWindow & window);
	void Growth();
	bool CollisionFruit();
	bool CollisionWall();
	bool CollisionSnake();

	void SpawnFruit();
	inline std::vector<sf::RectangleShape> GetShape() { return shape; }
	inline std::vector<sf::Vector2f> GetShapePosition() { return shapePosition; }
	inline direction GetSdir() { return sdir; }
	inline int GetLength() { return length; }
	inline sf::RectangleShape GetFruit() { return fruit; }
	inline void SetDirection(direction dir) { sdir = dir; }

};