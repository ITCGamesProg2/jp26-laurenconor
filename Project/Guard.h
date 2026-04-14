#pragma once
#include <SFML/Graphics.hpp>


class Guard
{
public:
	enum class GuardDirection {UP,DOWN,LEFT,RIGHT};


	Guard(sf::Vector2f startPos = sf::Vector2f{ 600,70 }, GuardDirection startDir = GuardDirection::LEFT);
	
	void Guard::update(double dt);//updates the thief


	void Guard::render(sf::RenderWindow& window);//renders the sprite

	void Guard::movement();//getting the state formovement
	void Guard::LRMovement();//moving the guard left and right
	void Guard::UDMovement();
	//void Guard::UDMovement();// not yet used 

	bool Guard::movingLeft();
	bool Guard::movingDown();

	void Guard::initSprites(sf::Vector2f startPos);

	//sets and gets position
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

	sf::FloatRect Guard::returnBounds();

	bool Guard::intersects(const sf::FloatRect& rect) const;

private:
	
	bool left = true;
	bool down = true;

	GuardDirection m_direction;//initalises the direction to left

	double m_speed{ 0.0f };//speed for guard
	sf::RectangleShape m_guard;//gets the basic rectangle shape
};

