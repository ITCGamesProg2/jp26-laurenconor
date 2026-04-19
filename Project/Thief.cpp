#include "Thief.h"
#include <iostream>

Thief::Thief()
{
	initSprites();
}

void Thief::update(double dt)
{
	handleKeyInput();
	boundChecking();
}



void Thief::initSprites()//gets the basic colours for the rectangle so i can visualise what is going on even without the proper sprite
{
	m_thief.setFillColor(sf::Color::Magenta);
	m_thief.setSize(sf::Vector2f{ 30,70 });
	m_thief.setPosition(sf::Vector2f{ 10,70 });


}
void Thief::render(sf::RenderWindow& window)
{
	
	window.draw(m_thief);
}

void Thief::handleKeyInput()//gets the key inputs and moves it in the direction the player wants
{
	sf::Vector2f pos = m_thief.getPosition();
	

	//	std::cout << "collliding" << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//up
		{
			m_thief.setPosition(sf::Vector2f{ pos.x  ,pos.y - 1 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//right
		{
			m_thief.setPosition(sf::Vector2f{ pos.x + 1, pos.y });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//left
		{
			m_thief.setPosition(sf::Vector2f{ pos.x - 1,  pos.y });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))//down
		{
			m_thief.setPosition(sf::Vector2f{ pos.x ,pos.y + 1 });
		}

		if (wallChecking())
		{
			m_thief.setPosition(pos);
		}
	
	
}


void Thief::setPosition(sf::Vector2f t_position)//set position so we can use it in the gane
{
	m_thief.setPosition(t_position);
}

sf::Vector2f Thief::getPosition() const//gets positon so we can use it in the game
{
	return m_thief.getPosition();
}

void Thief::boundChecking()
{

	if (m_thief.getPosition().x <= 0)
	{
		m_thief.setPosition(sf::Vector2f{ 0, getPosition().y });
		
	}
	else if (m_thief.getPosition().x + 30 >= 1440)
	{
		m_thief.setPosition(sf::Vector2f{ 1410, getPosition().y });
	}

	else if (m_thief.getPosition().y <= 0)
	{
		m_thief.setPosition(sf::Vector2f{ getPosition().x, 0});
	}

	else if (m_thief.getPosition().y + 70 >= 900)
	{
		m_thief.setPosition(sf::Vector2f{ getPosition().x, 830 });
	}

	
}

bool Thief::wallChecking()
{
	for (Items* box : m_boxes) //checks each box
	{
		if (box == nullptr) continue; //if not toching of the box it does nothing

		if (box->returnGlobalBounds().findIntersection(m_thief.getGlobalBounds())) //thief intersects with box
		{
			return true;
		}
	}
	return false;
}

void Thief::setBox(Items* box)
{
	m_boxes.push_back(box);
}

bool Thief::alive()
{
	if (m_lives > 0)
	{
		m_alive = true;
	}
	else
	{
		return false;
	}
}


void Thief::loseLife(double dt)
{
	if (m_lives <= 0) return;

	m_timer += dt;

	if (m_timer >= 1000)
	{
		m_lives -= 1;
		m_timer = 0.0f;
		std::cout << "remianing lives: " << m_lives;
	}

}

int Thief::getLives() const
{
	return m_lives;
}

sf::FloatRect Thief::returnBounds()
{
	return m_thief.getGlobalBounds();
}
