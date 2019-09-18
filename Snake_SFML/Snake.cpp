#include "Snake.h"
#include "Game.h"
#include <iostream>
#include <random>

Snake::Snake() : length(50), sdir(direction::STOP), shapeSize(20.f,20.f), movePixels(25)
{
	shape.resize(1000);
	shapePosition.resize(1000);
	for (int i = 0; i < length; i++)
	{
		shape[i].setSize(sf::Vector2f(shapeSize));
		shape[i].setPosition(400, 500 + i*movePixels);

		shapePosition[i] = shape[i].getPosition();

	}

	shape[0].setFillColor(sf::Color::Color(140, 140, 140));
	fruit.setFillColor(sf::Color::Red);
	fruit.setSize(sf::Vector2f(shapeSize));
	SpawnFruit();

}

Snake::~Snake() {}

void Snake::Control(sf::RenderWindow & window)
{	
	if (sdir != direction::STOP)
	{
		for (int i = length-1; i >= 0; i--)
		{
			shapePosition[i] = shape[i].getPosition();
			switch (sdir)
			{
			case direction::UP:
			{
				if (i == 0)
				{
					shape[i].move(0.f, -movePixels);
					shapePosition[i] = shape[i].getPosition();
				}
				else if (i > 0)
				{
					shapePosition[i] = shapePosition[i - 1];
					shape[i].setPosition(shapePosition[i]);
				}
				break;
			}
			case direction::DOWN:
			{
				if (i == 0)
				{
					shape[i].move(0.f, movePixels);
					shapePosition[i] = shape[i].getPosition();
				}
				else if (i > 0)
				{
					shapePosition[i] = shapePosition[i - 1];
					shape[i].setPosition(shapePosition[i]);
				}
				break;
			}
			case direction::LEFT:
			{
				if (i == 0)
				{
					shape[i].move(-movePixels, 0.f);
					shapePosition[i] = shape[i].getPosition();
				}
				else if (i > 0)
				{
					shapePosition[i] = shapePosition[i - 1];
					shape[i].setPosition(shapePosition[i]);
				}

				break;
			}
			case direction::RIGHT:
			{
				if (i == 0)
				{
					shape[i].move(movePixels, 0.f);
					shapePosition[i] = shape[i].getPosition();
				}
				else if (i > 0)
				{
					shapePosition[i] = shapePosition[i - 1];
					shape[i].setPosition(shapePosition[i]);
				}

				break;
			}
			case direction::STOP:
			{
				break;
			}
			}
		}
	}
}

void Snake::Growth()
{
	length++;
	shape[length - 1].setSize(sf::Vector2f(shapeSize));
}

bool Snake::CollisionFruit()
{
	if(shapePosition[0] == fruitPosition)
		return true;
	else
		return false;
}

bool Snake::CollisionWall()
{
	if (shapePosition[0].x >= Game::winSizeX || shapePosition[0].x < 0)
		return true;
	else if (shapePosition[0].y >= Game::winSizeY || shapePosition[0].y < 0)
		return true;
	else
		return false;
}

bool Snake::CollisionSnake()
{
	for (int i = 1; i <= length; i++)
	{
		if (shapePosition[0] == shapePosition[i])
			return true;
	}
	return false;
}


void Snake::SpawnFruit()
{
	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> x(1, 31);
	std::uniform_int_distribution<> y(1, 23);
	fruit.setPosition(x(eng)*movePixels, y(eng)*movePixels);

	for (int i = 0; i <= length; i++)
	{
		if (shapePosition[i] == fruitPosition)
		{
			fruit.setPosition(x(eng)*movePixels, y(eng)*movePixels); //TODO problem z respawn na snake
		}
	}
		fruitPosition = fruit.getPosition();

	std::cout << fruitPosition.x << " " << fruitPosition.y << std::endl;
	
}
