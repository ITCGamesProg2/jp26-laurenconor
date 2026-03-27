#include "Guard.h"
#include <iostream>

Guard::Guard()
{
	initSprites();
}

void Guard::update(double dt)
{
	
	movement();
	
}



void Guard::initSprites()
{
	m_guard.setFillColor(sf::Color::Red);
	m_guard.setSize(sf::Vector2f{ 30,70 });
	m_guard.setPosition(sf::Vector2f{ 600,70 });


}
void Guard::render(sf::RenderWindow& window)
{

	window.draw(m_guard);
}

void Guard::movement()
{
	
	switch (m_direction)
	{
	case GuardDirection::DOWN:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x ,m_guard.getPosition().y + 1 });
		break;
	case GuardDirection::UP:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x  ,m_guard.getPosition().y - 1 });
		break;
	case GuardDirection::LEFT:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x - 1,  m_guard.getPosition().y });
		break;
	case GuardDirection::RIGHT:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x + 1, m_guard.getPosition().y });
	default:
		break;
	}
}

void Guard::LRMovement()
{

	//m_direction = GuardDirection::LEFT;
	if (m_direction == GuardDirection::LEFT && m_guard.getPosition().x <= 0)
	{
		m_direction = GuardDirection::RIGHT;
	}
	if (m_direction == GuardDirection::RIGHT && m_guard.getPosition().x + 30 >= 1440)
	{
		m_direction = GuardDirection::LEFT;
	}

}

void Guard::setPosition(sf::Vector2f t_position)
{
	m_guard.setPosition(t_position);
}

sf::Vector2f Guard::getPosition() const
{
	return m_guard.getPosition();
}
