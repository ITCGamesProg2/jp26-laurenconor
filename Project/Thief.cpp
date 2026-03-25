#include "Thief.h"
#include <iostream>

Thief::Thief()
{
	initSprites();
}

void Thief::update(double dt)
{
	
}



void Thief::initSprites()
{
	m_thief.setFillColor(sf::Color::Magenta);
	m_thief.setSize(sf::Vector2f{ 30,70 });
	m_thief.setPosition(sf::Vector2f{ 400,70 });


}
void Thief::render(sf::RenderWindow& window)
{
	
	window.draw(m_thief);
	std::cout << "drawing thief";
}

