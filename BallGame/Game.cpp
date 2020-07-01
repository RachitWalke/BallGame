#include "Game.h"

//private funcs
void Game::initvariables()
{

	//initialize gamelogic variables
	platSpwanTimer = 0.f;
	platSpwanTimerMax = 100.f;
	maxPlat = 8;
	platspeed = -1.f;
	pointf = 0.f;
	pointi = 0;
	n = 25;
	health = 3;
	velocity.x = 2.5f;
	velocity.y = 2.5f;
	gameover = false;

	//text variables
	font.loadFromFile("FONTS/IMMORTAL.ttf");
	score.setFont(font);
	life.setFont(font);
	life.setPosition(280.f, 0.f);
	score.setFillColor(sf::Color(200, 0 ,0, 255));
	life.setFillColor(sf::Color(200, 0, 0, 255));

	//background 
	backgroundTex.loadFromFile("SPRITES/Bg.png");
	background.setTexture(backgroundTex);

	//game sprites textures
	ballTex.loadFromFile("SPRITES/Ball.png");
	platformTex.loadFromFile("SPRITES/platform.png");
	spikeTex.loadFromFile("SPRITES/Spike.png");

	//handleing highscore
	high.setFont(font);
	high.setCharacterSize(30);
	high.setPosition(165.f - high.getGlobalBounds().width,0.f);
	high.setFillColor(sf::Color(178,34,34,255));
	high.setOutlineThickness(1.f);
	high.setOutlineColor(sf::Color(0, 255, 127, 255));
	high.setString("HighScore: " + getHS);
}

void Game::initplatform()
{
	//initialize platform

	platform.setTexture(platformTex);
	platform.setPosition(200.f, 600.f);
	platform.setScale(1.1f, 1.5f);
	spikebase.setSize(sf::Vector2f(400.f, 5.f));
	spikebase.setPosition(0.f,50.f);
	spikebase.setFillColor(sf::Color(130, 130, 130, 255));
}

void Game::initSpike()
{
	spike.setTexture(spikeTex);
	spike.setScale(1.f, 0.5f);

	for (int i = 0; i <= 9; i++)
	{
		switch (i)
		{
		case 0:spike.setPosition(-5.f, 50.f);
			break;
		case 1:spike.setPosition(35.f, 50.f);
			break;
		case 2:spike.setPosition(75.f, 50.f);
			break;
		case 3:spike.setPosition(115.f, 50.f);
			break;
		case 4:spike.setPosition(155.f, 50.f);
			break;
		case 5:spike.setPosition(195.f, 50.f);
			break;
		case 6:spike.setPosition(235.f, 50.f);
			break;
		case 7:spike.setPosition(275.f, 50.f);
			break;
		case 8:spike.setPosition(315.f, 50.f);
			break;
		case 9:spike.setPosition(355.f, 50.f);
			break;
		default:
			break;
		}
		spikes.push_back(spike);
	}
}

void Game::initball()
{
	//initialize ball

	ball.setTexture(ballTex);
	ball.setOrigin(ball.getGlobalBounds().width / 2.f, ball.getGlobalBounds().height / 2.f);
	ball.setScale(0.8f, 0.8f);
	ball.setPosition(sf::Vector2f(200.f, 140.f));
}

void Game::initwindow()
{
	window.create(sf::VideoMode(400, 700), "BALL GAME", sf::Style::Titlebar | sf::Style::Close);
	window.setFramerateLimit(60);
}

void Game::initGOsc()
{

	//GameOver screen
	GameOversc.setFont(font);
	GameOversc.setString("GAME OVER !");
	GameOversc.setScale(1.2f, 1.2f);
	GameOversc.setPosition(
		window.getSize().x / 2.f - GameOversc.getGlobalBounds().width / 2.f,
		window.getSize().y / 2.f - GameOversc.getGlobalBounds().height / 2.f);

}

//cons and des
Game::Game() 
{
	highScore();
	initvariables();
	initwindow();
	initball();
	initSpike();
	initplatform();
	initGOsc();
}

Game::~Game()
{
}

//accesscors

const bool Game::running() const
{
	return window.isOpen();
}

const bool Game::getGameover() const
{
	return gameover;
}


void Game::pollEvents()
{
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();
	}

}

//Member functions
void Game::spawnplatform()
{
	/*
		-spwan platform with random position.
		-add platform to vector.
	*/

	int posCount = rand() % 3;

	switch (posCount)
	{
	case 0:
		platform.setPosition(
	    (window.getSize().x - 120.f),window.getSize().y );
		break;
	case 1:
		platform.setPosition(
		(window.getSize().x - 250.f),window.getSize().y );
		break;
	case 2:
		platform.setPosition(
		(window.getSize().x - 390.f),window.getSize().y );
		break;

	default:
		break;
	}


		//spwan platform
		platforms.push_back(platform);

}


void Game::updateplatform()
{
	//update timer for platform spwaning

	if (platforms.size() < maxPlat)
	{
		//spwan platform and reset timer

		if (platSpwanTimer > platSpwanTimerMax)
		{
				spawnplatform();
				platSpwanTimer = 0.f;
		}
		else
		{
			platSpwanTimer += 1.f;
		}
	}

	//moves platform in upward direction
	for (auto i = 0; i < platforms.size(); i++)
	{
		platforms[i].move(0.f, platspeed);

		//removing platform once reached top of window

		if (platforms[i].getPosition().y < (spikebase.getPosition().y))
		{
			platforms.erase(platforms.begin() + i);
		}
	}

}

void Game::moveBall()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		ball.move(sf::Vector2f( -velocity.x, 0.f));
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		ball.move(sf::Vector2f( velocity.x, 0.f));
	}

}

void Game::updateBall()
{

	/*
		-make ball move
		-detect collision with platforms
	*/

	ball.move(sf::Vector2f(0.f, velocity.y));
	moveBall();

	pointi = static_cast<int>(pointf);

	//detect collision with platform
	for (size_t i = 0; i < platforms.size(); i++)
	{
		if (ball.getGlobalBounds().intersects(platforms[i].getGlobalBounds()))
		{
			pointf+=0.05f;
		}
		while (ball.getGlobalBounds().intersects(platforms[i].getGlobalBounds()) &&
			(ball.getPosition().y < platforms[i].getGlobalBounds().top))
		{
			ball.move(sf::Vector2f(0.f, 1.5 * -velocity.y));
			moveBall();
		}
			
	}

	//Detect collision with spikes

	for (size_t i = 0; i < spikes.size(); i++)
	{
		if (ball.getGlobalBounds().intersects(spikes[i].getGlobalBounds()))
		{
			health -= 1;
			//reset ball
			ball.setPosition(sf::Vector2f(200.f, 200.f));
		}
	}

	//detect collision with screen

	if (ball.getGlobalBounds().left + 20.f < 0.f)
	{
		ball.setPosition(25.f, ball.getGlobalBounds().top);
		moveBall();
	}
	else if ((ball.getGlobalBounds().left  + ball.getGlobalBounds().width) -5.f  >= window.getSize().x)
	{
		ball.setPosition(window.getSize().x - ball.getGlobalBounds().width, ball.getGlobalBounds().top);
		moveBall();
	}

	//collision with bottom screen
	if (ball.getGlobalBounds().top + 10.f >= window.getSize().y)
	{
		health -= 1;
		//reset ball
		ball.setPosition(sf::Vector2f(200.f, 200.f));
	}

}


void Game::updateplatspeed()
{

	if (pointi > 0 && pointi % n == 0)
	{
		platspeed -= 0.5f;
		n += 25;
		platSpwanTimerMax -= 5;
		velocity.x += 0.2f;
		velocity.y += 0.2f;
	}

}

void Game::updateScore_Life()
{
	std::stringstream ss;
	ss << "Score: " << pointi;
	score.setString(ss.str());

	life.setString("Life: " + std::to_string(health));

}

void Game::renderBall_spike(sf::RenderTarget& target)
{
	//render ball
	target.draw(ball);
	target.draw(spikebase);

	//render spike
	for (auto &e : spikes)
	{
		target.draw(e);
	}

}

void Game::renderplatform(sf::RenderTarget& target)
{
	//renders platform on window
	for (auto &e : platforms)
	{
		target.draw(e);
	}

}

void Game::highScore()
{
	obj.open("E:\\Work\\VSProject\\BallGame\\BallGame\\Highscore.txt");
	if (obj.is_open())
	{
		std::getline(obj, getHS);
		//std::cout << getHS << std::endl;
		obj.close();
	}
	else
	{
		std::cout << "unable to open highscore file" << std::endl;
	}
}

void Game::menu()
{
	//mainmenu
	window.clear();
	window.draw(background);
	mm.draw(window);
	window.draw(high);
	window.display();
	mm.updateMenu(window);

	while (mm.getPlayGame())
	{
		//gameplay
		pollEvents();
		update();
		render();
		pm.updatePauseMenu(window);
		//pause menu
		while (pm.getPauseGame())
		{
			pollEvents();
			pm.drawContinue(window);
			window.display();
			pm.updatePauseMenu(window);
		}
	}
}


void Game::update()
{
	if (gameover == false)
	{
		updateplatform();
		updateBall();
		updateplatspeed();
		updateScore_Life();
		//std::cout << "life = " << health << std::endl;
	}
	
	if (health <= 0)
	{
		gameover = true;
	}
}

void Game::render()
{
	window.clear();
	window.draw(background);
	pm.drawPause(window);

	//render objects
	renderplatform(window);
	renderBall_spike(window);

	//render GUI
	window.draw(score);
	window.draw(life);

	//game over screen
	if (health <= 0)
	{
		//game Over screen
		window.draw(GameOversc);
		//setting new highscore
		std::stringstream sHS(getHS);
		sHS >> checkHS;
		if (pointi > checkHS)
		{
			obj.open("E:\\Work\\VSProject\\BallGame\\BallGame\\Highscore.txt", std::ofstream::out | std::ofstream::trunc);
			obj << std::to_string(pointi);
		}
		obj.close();
	}


	window.display();
}
