#pragma once
#include <SFML/Graphics.hpp>


class Thief 
{
public:

	Thief();

	void Thief::update(double dt);//updates the thief

	void Thief::render(sf::RenderWindow& window);//renders the sprite
	void Thief::handleKeyInput();//for movement

	void Thief::increaseSpeed();
	void Thief::decreaseSpeed();
	void Thief::increaseRotation();
	void Thief::decreaseRotation();

	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

private:
	void Thief::initSprites();

//	sf::Sprite m_thief;
	double m_speed{ 0.0f };//speed for thief
	sf::Angle m_rotation{ sf::degrees(0.0) };
	sf::RectangleShape m_thief;
};
