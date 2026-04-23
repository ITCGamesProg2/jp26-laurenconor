#include "Guard.h"
#include <iostream>

Guard::Guard(sf::Vector2f startPos, GuardDirection startDir, GuardMovement movement) : m_direction(startDir), m_movement(movement)
{
	initSprites(startPos);
}

void Guard::update(double dt, sf::Vector2f thiefPos)
{
	if (m_isChasing)//if the guard is chasing
	{
		chaseTarget(thiefPos, dt);//sets where it needs to go in
	}
	else
	{
		if (m_movement == GuardMovement::LEFTRIGHT)//if guard is moving left, vision cone points left
	{
			LRMovement();
		}
		else
		{
			UDMovement();
		}
		
		movement();
	}
	boundaryChecking();//checks if guard is colliding with the edge of the secreen & flips it around if it is
}





void Guard::initSprites(sf::Vector2f startPos)//Gets the texture, sprite and position of sprite
{	
	if (!m_guardTexture.loadFromFile("ResourceFiles/Images/walking_guard.png"))
	{
		std::cout << "Guard not loading :( " <<std::endl;
	}
	
	
	m_guardSprite = sf::Sprite(m_guardTexture);//sets texture to sprite
	m_guardSprite.setTextureRect(sf::IntRect{ { 16,10}, {42, 60} });//sets texture rect for singe guard sprite 
	m_guardSprite.setScale(sf::Vector2f{ 2,2 });//sets scale of the sprite
	m_guardSprite.setPosition(startPos);//sets position for the guards

	
}
void Guard::render(sf::RenderWindow& window)//draws guard sprite
{
	window.draw(m_guardSprite);
}

void Guard::movement()//gets movment for each direction
{
	
	switch (m_direction)
	{
	case GuardDirection::DOWN:
		m_guardSprite.setPosition(sf::Vector2f{ m_guardSprite.getPosition().x ,m_guardSprite.getPosition().y + 1 }); //moves guard down
		//down == true;
		break;
	case GuardDirection::UP:
		m_guardSprite.setPosition(sf::Vector2f{ m_guardSprite.getPosition().x  ,m_guardSprite.getPosition().y - 1 });//moves guard up
		// == true;
		break;
	case GuardDirection::LEFT:
		m_guardSprite.setPosition(sf::Vector2f{ m_guardSprite.getPosition().x - 1,  m_guardSprite.getPosition().y });//moves guard left
		break;
	case GuardDirection::RIGHT:
		m_guardSprite.setPosition(sf::Vector2f{ m_guardSprite.getPosition().x + 1, m_guardSprite.getPosition().y });//moves guard right
	default:
		break;
	}
}

void Guard::LRMovement()//moves the guard in specific patterns - left and right on the map dosent go past the edge of the screen
{

	//m_direction = GuardDirection::LEFT;
	if (m_direction == GuardDirection::LEFT && m_guardSprite.getPosition().x <= 0)
	{
		m_direction = GuardDirection::RIGHT;//if player is at the very left of the screen, it starts moving in the opposite direction which is right 
		m_guardSprite.setPosition({ 0,m_guardSprite.getPosition().y });
		left = false;	
	}
	if (m_direction == GuardDirection::RIGHT && m_guardSprite.getPosition().x + 30 >= 1440)
	{
		m_direction = GuardDirection::LEFT;//if player is at the right of the screen it will move in the left direction once again
		m_guardSprite.setPosition({ 1410,m_guardSprite.getPosition().y });
		left = true;
	}
}

void Guard::UDMovement()
{
	if (m_direction == GuardDirection::UP && m_guardSprite.getPosition().y <= 0)
	{
		m_direction = GuardDirection::DOWN;//if player is at the very left of the screen, it starts moving in the opposite direction which is right 
		down = true;
	}
	
	if (m_direction == GuardDirection::DOWN && m_guardSprite.getPosition().y + 70 >= 900)
	{
		m_direction = GuardDirection::UP;//if player is at the right of the screen it will move in the left direction once again
		down = false;
	}

}

void Guard::boundaryChecking()
{
	if (m_guardSprite.getPosition().x < 0)//checks left of screen
	{
		m_direction = GuardDirection::RIGHT;//changes guards direction to right
	}
	else if( m_guardSprite.getPosition().x + 30 > 1440)//checks right of screen
	{
		m_direction = GuardDirection::LEFT;//changes guards direction to left
	}
	else if (m_guardSprite.getPosition().y < 0)//checks bottom of screen
	{
		m_direction = GuardDirection::DOWN;//changes guards direction to up

	}	
	else if (m_guardSprite.getPosition().y + 70 > 900)//checks top of screen
	{
		m_direction = GuardDirection::UP;//changes guards direction to down
	}
	
}

bool Guard::movingLeft()
{

	return left;//returns true if guard is moving left
}

bool Guard::movingDown()
{

	return down;//returns true if guard is moving down
}

void Guard::setPosition(sf::Vector2f t_position) //we can call this to set the position in the game class or another class we might need later
{

	m_guardSprite.setPosition(t_position);
}

sf::Vector2f Guard::getPosition() const//can be used in game later for collision etc
{
	return m_guardSprite.getPosition();
}


bool Guard::intersects(const sf::FloatRect& rect) const//if the guard intersects withe the player
{
		
		if (m_guardSprite.getGlobalBounds().findIntersection(rect))
		{
			
			return true;
		}

	return false;
}

void Guard::setChasing(bool chasing)//sets the guards status to chasing so it follows the player
{
	m_isChasing = chasing;
	m_speed = 2.0;
}

void Guard::chaseTarget(sf::Vector2f targetPos, double dt)//gets the direction and distance guard should chase player
{
	sf::Vector2f guardPos = m_guardSprite.getPosition();
	sf::Vector2f direction = targetPos - guardPos;

	float length = std::sqrt(direction.x * direction.x + direction.y * direction.y); //getting length of vector so we can normalise it and use it

	if (length > 0.0f)//makes sure guards are actually in a different position to the thief
	{
		direction /= length;//normalise (moves smoother)
	}
	if (std::abs(direction.x) > std::abs(direction.y))//if the absolute x direction is greater than the y
	{
		if (direction.x > 0)//if the x position of the thief is greater than the guard, the guard needs to move right
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
		if (direction.y > 0)//if the y position of the thief is greater than the guard, the guard needs to move down
		{
			m_direction = GuardDirection::DOWN;
		}
		else
		{
			m_direction = GuardDirection::UP;
		}
	}
	float chaseSpeed = 0.5f;//slows the guard down when its chasing thief
	m_guardSprite.setPosition(guardPos + direction * chaseSpeed);//sets the new position
	
}

sf::FloatRect Guard::returnBounds()//returns position for collision checking
{
	return m_guardSprite.getGlobalBounds();
}