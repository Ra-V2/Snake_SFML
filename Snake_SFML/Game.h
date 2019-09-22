#pragma once
#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "Fruit.h"

class Game
{
private:

	static constexpr short FPS = 10;
	sf::Time MS_PER_FRAME;
	bool lose;

public:

	static constexpr short winSizeX = 800;
	static constexpr short winSizeY = 600;
	static constexpr float movePixels = 25.f;
	static constexpr float shapeSize = 20.f;

	Game();

	void StartGame();
	bool GameOver(sf::RenderWindow & window, Snake & snake, int score);
	void ProcessInput(sf::RenderWindow & window, Snake & snake);
	void Update(sf::RenderWindow & window, Snake & snake, Fruit & fruit);
	void Draw(sf::RenderWindow & window, Snake & snake, Fruit & fruit);
	void Collision(Snake & snake, Fruit & fruit);
};
