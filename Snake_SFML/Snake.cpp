#include "Snake.h"
#include "Game.h"


Snake::Snake() : length(3), sdir(direction::STOP)
{
	shape.resize(101);
	shapePosition.resize(101);

	for (int i = 0; i < length; i++) //set up snake
	{
		shape[i].setSize(sf::Vector2f(Game::shapeSize,Game::shapeSize));
		shape[i].setPosition(400, 500 + i*Game::movePixels);

		shapePosition[i] = shape[i].getPosition();

	}

	shape[0].setFillColor(sf::Color::Color(140, 140, 140)); //set snake head color
}

void Snake::Control(sf::RenderWindow & window) //move snake
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
					shape[i].move(0.f, -Game::movePixels);
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
					shape[i].move(0.f, Game::movePixels);
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
					shape[i].move(-Game::movePixels, 0.f);
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
					shape[i].move(Game::movePixels, 0.f);
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

void Snake::Growth() //snake growth up
{
	length++;
	shape[length - 1].setSize(sf::Vector2f(Game::shapeSize, Game::shapeSize));
}

const bool Snake::CollisionFruit(const Fruit & fruit) //detect snake hit fruit
{
	if (shapePosition[0] == fruit.fruitPosition)
		return true;
	else
		return false;
}

const bool Snake::CollisionWall() //detect snake hit wall
{
	if (shapePosition[0].x >= Game::winSizeX || shapePosition[0].x < 0)
		return true;
	else if (shapePosition[0].y >= Game::winSizeY || shapePosition[0].y < 0)
		return true;
	else
		return false;
}

const bool Snake::CollisionSnake() //detect snake hit himself
{
	for (int i = 1; i <= length; i++)
	{
		if (shapePosition[0] == shapePosition[i])
			return true;
	}
	return false;
}
