#include "Game.h"
#include "Fruit.h"

Game::Game()
{
	MS_PER_FRAME = sf::milliseconds(1000/FPS);

	lose = false; //checks whether to continue playing
	
	StartGame();
}

void Game::StartGame()
{
	sf::RenderWindow window(sf::VideoMode(winSizeX, winSizeY, 32), "SNAKE by RaV");
	int score = 0;
	do
	{

	Snake snake;
	Fruit fruit(snake);
	sf::Clock clock;

	while (window.isOpen() && !lose) //game loop
	{
		sf::Time start = clock.getElapsedTime();
		ProcessInput(window, snake);
		Update(window, snake, fruit);
		if (!lose)
			Draw(window, snake,fruit);
		sf::Time stop = clock.getElapsedTime();
		sf::sleep(start + MS_PER_FRAME - stop);
		score = snake.GetLength();
		if (score == 100) //if player beat score 100 loop ends
		{
			lose = true;
			break;
		}
	}

	if (GameOver(window, snake, score)) //check if the font has loaded
		break;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) //restart game
		lose = false;

	sf::Event eventclose;
	window.pollEvent(eventclose);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || eventclose.type == sf::Event::Closed) //exit game
		window.close();

	} while (window.isOpen());
}

void Game::Update(sf::RenderWindow & window, Snake & snake, Fruit & fruit)
{
	Collision(snake, fruit);
	snake.Control(window);
}

void Game::Draw(sf::RenderWindow & window, Snake & snake, Fruit & fruit)
{
	window.clear();
	for(int i = 0; snake.GetLength() > i; i++ ) //loop for all shapes
		window.draw(snake.GetShape()[i]);
	window.draw(fruit.GetFruit());
	window.display();

}


void Game::ProcessInput(sf::RenderWindow & window, Snake & snake) //set direction
{

	if (snake.GetSdir() == direction::STOP) //start snake position
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


	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) //close window while playing
			window.close();

		if (event.type == sf::Event::KeyPressed) //normal snake control
		{
				if (snake.GetSdir() == direction::UP || snake.GetSdir() == direction::DOWN)
				{

					if (event.key.code == sf::Keyboard::A)
					{
						snake.SetDirection(direction::LEFT);
						break;
					}

					else if (event.key.code == sf::Keyboard::D)
					{
						snake.SetDirection(direction::RIGHT);
						break;
					}
				}

				else if (snake.GetSdir() == direction::RIGHT || snake.GetSdir() == direction::LEFT)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						snake.SetDirection(direction::UP);
						break;
					}

					else if (event.key.code == sf::Keyboard::S)
					{
						snake.SetDirection(direction::DOWN);
						break;
					}
				}

		}
	}
}

void Game::Collision(Snake & snake, Fruit & fruit) //check collision
{
	if (snake.CollisionFruit(fruit))
	{
		snake.Growth();
		fruit.SpawnFruit(snake);
	}
	if (snake.CollisionSnake() || snake.CollisionWall())
	{
		lose = true;
	}
}

bool Game::GameOver(sf::RenderWindow & window, Snake & snake, int score) //load font and display text
{
	sf::Font font;
	sf::Text text;

	if (!font.loadFromFile("VCR_OSD_MONO.ttf"))
	{
		return true;
	}

	text.setFont(font);
	text.setString("Congratulations!\nYour score:" + std::to_string(score) + "\nClick ENTER to restart or ESCAPE to exit");
	text.setCharacterSize(28);
	text.setFillColor(sf::Color::White);
	sf::FloatRect textRect = text.getLocalBounds(); //center text
	text.setOrigin(textRect.left + textRect.width / 2.0f,
		textRect.top + textRect.height / 2.0f);
	text.setPosition(sf::Vector2f(winSizeX / 2.0f, winSizeY / 2.0f));

	window.clear();
	window.draw(text);
	window.display();

	return false;
}
