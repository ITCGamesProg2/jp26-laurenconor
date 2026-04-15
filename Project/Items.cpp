#include "Items.h"
#include <iostream>

Items::Items(sf::Vector2f position)
{
	initSprites(position);
}

void Items::update(double dt)
{
	//handleKeyInput();
}



void Items::initSprites(sf::Vector2f position)//gets the basic colours for the rectangle so i can visualise what is going on even without the proper sprite
{
	m_box.setFillColor({153, 102, 51});
	m_box.setSize(sf::Vector2f{ 450,75 });
	m_box.setPosition(sf::Vector2f{ position });

}
void Items::render(sf::RenderWindow& window)
{

	window.draw(m_box);
}
/*
void Items::handleKeyInput()//gets the key inputs and moves it in the direction the player wants
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//up
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x  ,m_thief.getPosition().y - 1 });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//right
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x + 1, m_thief.getPosition().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//left
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x - 1,  m_thief.getPosition().y });
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))//down
	{
		m_thief.setPosition(sf::Vector2f{ m_thief.getPosition().x ,m_thief.getPosition().y + 1 });
	}
}*/


void Items::setPosition(sf::Vector2f t_position)//set position so we can use it in the gane
{
	m_box.setPosition(t_position);
}

sf::Vector2f Items::getPosition() const//gets positon so we can use it in the game
{
	return m_box.getPosition();
}

/*
sf::FloatRect Thief::returnBounds()
{
	return m_thief.getGlobalBounds();
}*/