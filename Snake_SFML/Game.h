#pragma once
#include "Snake.h"
#include "SFML/Graphics.hpp"
#include <vector>

class Game
{
private:
	static constexpr short FPS = 10;
	sf::Time MS_PER_FRAME;
	bool lose;

public:

	static constexpr short winSizeX = 800;
	static constexpr short winSizeY = 600;

	Game();
	~Game();

	void StartGame();
	void ProcessInput(sf::RenderWindow & window, Snake & snake);
	void Update(sf::RenderWindow & window, Snake & snake);
	void Draw(sf::RenderWindow & window, Snake & snake);
	void Collision(Snake & snake);
};
