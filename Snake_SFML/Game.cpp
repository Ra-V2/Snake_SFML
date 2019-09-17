#include "Game.h"
//include <iostream>

Game::Game()
{
	MS_PER_FRAME = sf::milliseconds(1000/FPS);

	lose = false;

}

Game::~Game()
{
}

void Game::StartGame()
{
	sf::RenderWindow window(sf::VideoMode(winSizeX, winSizeY, 32), "SNAKE");
	Snake snake;
	sf::Clock clock;
	while (window.isOpen() && !lose)
	{
		sf::Time start = clock.getElapsedTime();
		ProcessInput(window, snake);
		Update(window, snake);
		Draw(window, snake);
		sf::Time stop = clock.getElapsedTime();
		sf::sleep(start + MS_PER_FRAME - stop);
	}
}

void Game::Update(sf::RenderWindow & window, Snake & snake)
{
	Collision(snake);
	snake.Control(window);
}

void Game::Draw(sf::RenderWindow & window, Snake & snake)
{
	window.clear();
	for(int i = 0; snake.GetLength() > i; i++ )
		window.draw(snake.shape[i]);
	window.draw(snake.GetFruit());
	window.display();

}


void Game::ProcessInput(sf::RenderWindow & window, Snake & snake)
{
	sf::Event eventclose;
	while (window.pollEvent(eventclose))
	{
		if (eventclose.type == sf::Event::Closed)
			window.close();
	}
	if (sf::Event::KeyPressed)
	{
		if (snake.GetSdir() == direction::STOP)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				snake.SetDirection(direction::UP);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				snake.SetDirection(direction::LEFT);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				snake.SetDirection(direction::RIGHT);
			}
		}
		else if (snake.GetSdir() == direction::UP)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				snake.SetDirection(direction::LEFT);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				snake.SetDirection(direction::RIGHT);
			}
		}
		else if (snake.GetSdir() == direction::DOWN)
		{

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				snake.SetDirection(direction::LEFT);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				snake.SetDirection(direction::RIGHT);
			}
		}

		else if (snake.GetSdir() == direction::RIGHT)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				snake.SetDirection(direction::UP);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				snake.SetDirection(direction::DOWN);
			}
		}
		else if (snake.GetSdir() == direction::LEFT)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				snake.SetDirection(direction::UP);
			}

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				snake.SetDirection(direction::DOWN);
			}

		}
	}
}

void Game::Collision(Snake & snake)
{
	if (snake.CollisionFruit())
	{
		snake.Growth();

	}
	if (snake.CollisionWall())
	{
		lose = true;
	}
}
