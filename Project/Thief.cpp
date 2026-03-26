#include "Thief.h"
#include <iostream>

Thief::Thief()
{
	initSprites();
}

void Thief::update(double dt)
{
	handleKeyInput();

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
}

void Thief::handleKeyInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x  ,m_thief.getPosition().y - 1 });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x + 1, m_thief.getPosition().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x - 1,  m_thief.getPosition().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x ,m_thief.getPosition().y + 1 });
	}


}


void Thief::setPosition(sf::Vector2f t_position)
{
	m_thief.setPosition(t_position);
}

sf::Vector2f Thief::getPosition() const
{
	return m_thief.getPosition();
}
