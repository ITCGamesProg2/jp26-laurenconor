#pragma once
#include <SFML/Graphics.hpp>


class Thief 
{
public:

	Thief();

	void Thief::update(double dt);//updates the thief

	void Thief::initSprites();//gets the basic shaoe for the thief

	void Thief::render(sf::RenderWindow& window);//renders the sprite
	void Thief::handleKeyInput();//for movement

	//gets and sets position to be used by the scentTrail class
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

private:

	double m_speed{ 0.0f };//speed for thief
	sf::RectangleShape m_thief;//gets the rectangle shape for the thief
};
