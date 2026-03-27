#pragma once
#include <SFML/Graphics.hpp>


class Guard
{
public:

	Guard();

	void Guard::update(double dt);//updates the thief

	void Guard::render(sf::RenderWindow& window);//renders the sprite
	void Guard::movement();//getting the state formovement
	void Guard::LRMovement();
	void Guard::UDMovement();

	enum class GuardDirection{UP,DOWN, LEFT, RIGHT};
	GuardDirection m_direction{ GuardDirection::LEFT };

	void Guard::increaseSpeed();
	void Guard::decreaseSpeed();
	void Guard::increaseRotation();
	void Guard::decreaseRotation();

	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

private:
	void Guard::initSprites();

	//	sf::Sprite m_thief;
	int m_ranDir = 0;
	float m_time;
	double m_speed{ 0.0f };//speed for thief
	sf::Angle m_rotation{ sf::degrees(0.0) };
	sf::RectangleShape m_guard;
};

