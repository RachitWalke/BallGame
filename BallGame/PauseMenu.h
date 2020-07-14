#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>
#include"state.h"


class PauseMenu : public state
{

private:
	   //variables;
	sf::Font font;
	sf::Text ContinueButton;
	sf::Texture pauseTex;
	sf::Sprite pauseBack;

public:

	//cons and des
	PauseMenu();
	~PauseMenu();

	//member funcs
	void update(sf::Vector2f mpos, int& StateID) override;
	void render(sf::RenderTarget& target) override;
};

