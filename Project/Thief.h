#pragma once
#include <SFML/Graphics.hpp>


class Thief 
{
public:

	Thief();

	void Thief::update(double dt);
	void Thief::render(sf::RenderWindow& window);
	
private:
	void Thief::initSprites();

//	sf::Sprite m_thief;
	sf::RectangleShape m_thief;
};
