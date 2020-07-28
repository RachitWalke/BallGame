#pragma once
#include"state.h"

class SplashScreen : public state
{
public:
	SplashScreen();
	~SplashScreen();

	void update(sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;

private:
	sf::Texture txr;
	sf::Sprite sp;
	uint8_t alpha;
	sf::Clock clk;
};

