#include "Fruit.h"
#include "Game.h"
#include <random>

Fruit::Fruit(const Snake & snake)
{
	fruit.setFillColor(sf::Color::Red); //set fruit color

	fruit.setSize(sf::Vector2f(Game::shapeSize,Game::shapeSize));

	SpawnFruit(snake);
}

void Fruit::SpawnFruit(const Snake & snake)
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> x(1, 31);
	std::uniform_int_distribution<> y(1, 23);
	bool safe = true;

	do   // check if fruit respawn on snake
	{
		fruit.setPosition(x(eng)*Game::movePixels, y(eng)*Game::movePixels);
		fruitPosition = fruit.getPosition();

		for (int i = 0; i < snake.length; i++)
		{
			if (snake.shapePosition[i] == fruitPosition)
			{
				safe = false;
				break;
			}
			else
				safe = true;
		}
	} while (!safe);

}
