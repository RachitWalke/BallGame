#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<memory>

class state
{
	public:

		virtual void update(sf::Vector2f mpos, int& StateID) = 0;
		virtual void render(sf::RenderTarget& target) = 0;

};