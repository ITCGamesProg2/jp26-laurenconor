#pragma once
#include <SFML/Graphics.hpp>


class Guard
{
public:

	Guard();

	void Guard::update(double dt);//updates the thief

	void Guard::render(sf::RenderWindow& window);//renders the sprite

	void Guard::movement();//getting the state formovement
	void Guard::LRMovement();//moving the guard left and right
	//void Guard::UDMovement();// not yet used 

	void Guard::initSprites();

	//sets and gets position
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

private:
	

	enum class GuardDirection { UP, DOWN, LEFT, RIGHT };
	GuardDirection m_direction{ GuardDirection::LEFT };//initalises the direction to left

	double m_speed{ 0.0f };//speed for guard
	sf::RectangleShape m_guard;//gets the basic rectangle shape
};

