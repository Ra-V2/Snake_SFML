#pragma once
#include "SFML/Graphics.hpp"


enum class direction { STOP, UP, DOWN, LEFT, RIGHT };

class Snake
{
private:
	int length;
	int movePixels;
	direction sdir;
	sf::RectangleShape fruit;
	sf::Vector2f fruitPosition;
	sf::Vector2f shapeSize;
	bool fruitSpawned;

public:
	std::vector<sf::RectangleShape> shape;
	std::vector<sf::Vector2f> shapePosition;
	Snake();
	~Snake();
	void Control(sf::RenderWindow & window);
	void Growth();
	bool CollisionFruit();
	bool CollisionWall();

	void SpawnFruit(sf::Vector2f location);
	inline direction GetSdir() { return sdir; }
	inline int GetLength() { return length; }
	inline sf::RectangleShape GetFruit() { return fruit; }
	inline void SetDirection(direction dir) { sdir = dir; }

};