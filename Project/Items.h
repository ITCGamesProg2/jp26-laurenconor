#pragma once
#include <SFML/Graphics.hpp>


class Items
{
public:

	Items(sf::Vector2f t_position);

	void Items::update(double dt);//updates the thief

	void Items::initSprites(sf::Vector2f position);//gets the basic shaoe for the thief

	void Items::render(sf::RenderWindow& window);//renders the sprite
	void Items::handleKeyInput();//for movement

	//gets and sets position to be used by the scentTrail class
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

	//sf::FloatRect Items::returnBounds();


private:

	double m_speed{ 0.0f };//speed for thief
	sf::RectangleShape m_box;//gets the rectangle shape for the box for jewlery
};

