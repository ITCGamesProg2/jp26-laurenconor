#include "Guard.h"
#include <iostream>

Guard::Guard(sf::Vector2f startPos, GuardDirection startDir, GuardMovement movement) : m_direction(startDir), m_movement(movement)
{
	initSprites(startPos);
}

void Guard::update(double dt, sf::Vector2f thiefPos)
{
	if (m_isChasing)
	{
		chaseTarget(thiefPos, dt);
	}
	else
	{
		if (m_movement == GuardMovement::LEFTRIGHT)
	{
			LRMovement();
		}
		else
		{
			UDMovement();
		}
		
		movement();
	}
	boundaryChecking();
}

//Guard::getDirection() const
//{
//	return m_direction;
//}



void Guard::initSprites(sf::Vector2f startPos)//gets the basic rectangle for now since its easier and i can focus more on the coding , will add the sprite later 
{
	m_guard.setFillColor(sf::Color::Red);
	m_guard.setSize(sf::Vector2f{ 30,70 });
	m_guard.setPosition(startPos);

	
}
void Guard::render(sf::RenderWindow& window)
{
	window.draw(m_guard);
}

void Guard::movement()//gets movment for each direction
{
	
	switch (m_direction)
	{
	case GuardDirection::DOWN:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x ,m_guard.getPosition().y + 1 }); //moves guard down
		//down == true;
		break;
	case GuardDirection::UP:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x  ,m_guard.getPosition().y - 1 });//moves guard up
		// == true;
		break;
	case GuardDirection::LEFT:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x - 1,  m_guard.getPosition().y });//moves guard left
		break;
	case GuardDirection::RIGHT:
		m_guard.setPosition(sf::Vector2f{ m_guard.getPosition().x + 1, m_guard.getPosition().y });//moves guard right
	default:
		break;
	}
}

void Guard::LRMovement()//moves the guard in specific patterns - left and right on the map dosent go past the edge of the screen
{

	//m_direction = GuardDirection::LEFT;
	if (m_direction == GuardDirection::LEFT && m_guard.getPosition().x <= 0)
	{
		m_direction = GuardDirection::RIGHT;//if player is at the very left of the screen, it starts moving in the opposite direction which is right 
		m_guard.setPosition({ 0,m_guard.getPosition().y });
		left = false;	
	}
	if (m_direction == GuardDirection::RIGHT && m_guard.getPosition().x + 30 >= 1440)
	{
		m_direction = GuardDirection::LEFT;//if player is at the right of the screen it will move in the left direction once again
		m_guard.setPosition({ 1410,m_guard.getPosition().y });
		left = true;
	}
}

void Guard::UDMovement()
{
	if (m_direction == GuardDirection::UP && m_guard.getPosition().y <= 0)
	{
		m_direction = GuardDirection::DOWN;//if player is at the very left of the screen, it starts moving in the opposite direction which is right 
		down = true;
	}
	
	if (m_direction == GuardDirection::DOWN && m_guard.getPosition().y + 70 >= 900)
	{
		m_direction = GuardDirection::UP;//if player is at the right of the screen it will move in the left direction once again
		down = false;
	}

}

void Guard::boundaryChecking()
{
	if (m_guard.getPosition().x < 0)
	{
		m_direction = GuardDirection::RIGHT;
	}
	else if( m_guard.getPosition().x + 30 > 1440)
	{
		m_direction = GuardDirection::LEFT;
	}
	else if (m_guard.getPosition().y < 0)
	{
		m_direction = GuardDirection::DOWN;

	}	
	else if (m_guard.getPosition().y + 70 > 900)
	{
		m_direction = GuardDirection::UP;
	}
	
}

bool Guard::movingLeft()
{

	return left;
}

bool Guard::movingDown()
{

	return down;
}

void Guard::setPosition(sf::Vector2f t_position) //we can call this to set the position in the game class or another class we might need later
{

	m_guard.setPosition(t_position);
}

sf::Vector2f Guard::getPosition() const//can be used in game later for collision etc
{
	return m_guard.getPosition();
}


bool Guard::intersects(const sf::FloatRect& rect) const
{
		
		if (m_guard.getGlobalBounds().findIntersection(rect))
		{
			return true;
		}

	return false;
}

void Guard::setChasing(bool chasing)
{
	m_isChasing = chasing;

}

void Guard::chaseTarget(sf::Vector2f targetPos, double dt)
{
	sf::Vector2f guardPos = m_guard.getPosition();
	sf::Vector2f direction = targetPos - guardPos;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y); //getting length of vector so we can normalise it and use it

	if (length > 0.0f)
	{
		direction /= length;//normalise (moves smoother)
	}
	if (std::abs(direction.x) > std::abs(direction.y))
	{
		if (direction.x > 0)
		{
			m_direction = GuardDirection::RIGHT;
		}
		else
		{
			m_direction = GuardDirection::LEFT;
		}
	}
	else
	{
		if (direction.y > 0)
		{
			m_direction = GuardDirection::DOWN;
		}
		else
		{
			m_direction = GuardDirection::UP;
		}
	}
	float chaseSpeed = 1.0f;
	m_guard.setPosition(guardPos + direction * chaseSpeed);
	
}

sf::FloatRect Guard::returnBounds()
{
	return m_guard.getGlobalBounds();
}
