#include "Thief.h"
#include <iostream>

Thief::Thief()
{
	m_items = new Items(sf::Vector2f{ 0,0 });
	initSprites();
}

void Thief::update(double dt)
{
	handleKeyInput();
	boundChecking();
}



void Thief::initSprites()//gets the basic colours for the rectangle so i can visualise what is going on even without the proper sprite
{
	if (!m_thiefTexture.loadFromFile("ResourceFiles/Images/thief_crouch.png"))
	{
		std::cout << "error loading thief sprite" << std::endl;
	}
	m_thief.setFillColor(sf::Color::Magenta);
	
	


	m_thiefSprite = sf::Sprite{ m_thiefTexture };
	m_thiefSprite.setTextureRect(sf::IntRect({ 15,3 }, { 30, 67 }));
	m_thiefSprite.setScale(sf::Vector2f{ 2,2 });
	m_thiefSprite.setPosition(sf::Vector2f{ 10,70 });


}
void Thief::render(sf::RenderWindow& window)
{
	//window.draw(m_thief);
	window.draw(m_thiefSprite);
}

void Thief::handleKeyInput()//gets the key inputs and moves it in the direction the player wants
{
	sf::Vector2f pos = m_thiefSprite.getPosition();
	

	//	std::cout << "collliding" << std::endl;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))//up
		{
			m_thiefSprite.setPosition(sf::Vector2f{ pos.x  ,pos.y - 1 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))//right
		{
			m_thiefSprite.setPosition(sf::Vector2f{ pos.x + 1, pos.y });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))//left
		{
			m_thiefSprite.setPosition(sf::Vector2f{ pos.x - 1,  pos.y });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))//down
		{
			m_thiefSprite.setPosition(sf::Vector2f{ pos.x ,pos.y + 1 });
		}

		if (wallChecking())
		{
			m_thiefSprite.setPosition(pos);
		}
	
		for (Items* item : m_boxes)
		{
			if (item == nullptr) continue;
			if (item->retCloakBounds().findIntersection(m_thiefSprite.getGlobalBounds()))
			{
				if (m_items->getCloakVisible())
				{
					item->setCloakVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}
			}
			if (item->retCrownBounds().findIntersection(m_thiefSprite.getGlobalBounds()))
			{
				if (m_items->getCrownVisible())
				{
					item->setCrownVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}
			}
			if (item->retJewlBounds().findIntersection(m_thiefSprite.getGlobalBounds()))
			{
				if (m_items->getJewlVisible())
				{
					item->setJewlVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}
			}
			if (item->retSignBounds().findIntersection(m_thiefSprite.getGlobalBounds()) )
			{
				m_exit = true;
			}
			if (item->retButBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getButVisible())
			{
				if (m_items->getButVisible())
				{
					item->setButVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}

			}
			if (item->retBookBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getBookVisible())
			{
				if (m_items->getBookVisible())
				{
					item->setBookVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}
			}
			if (item->retHatBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getHatVisible())
			{
				if (m_items->getHatVisible())
				{
					item->setHatVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}
			}
			if (item->retWeaponsBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getWeaponsVisible())
			{
				if (m_items->getWeaponsVisible())
				{
					item->setWeaponsVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;
				}
			}
		}

}


void Thief::setPosition(sf::Vector2f t_position)//set position so we can use it in the gane
{
	m_thiefSprite.setPosition(t_position);
}

sf::Vector2f Thief::getPosition() const//gets positon so we can use it in the game
{
	return m_thiefSprite.getPosition();
}

void Thief::boundChecking()
{

	if (m_thiefSprite.getPosition().x <= 0)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ 0, getPosition().y });
		
	}
	else if (m_thiefSprite.getPosition().x + 30 >= 1440)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ 1410, getPosition().y });
	}

	else if (m_thiefSprite.getPosition().y <= 0)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ getPosition().x, 0});
	}

	else if (m_thiefSprite.getPosition().y + 70 >= 900)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ getPosition().x, 830 });
	}

}

bool Thief::wallChecking()
{
	for (Items* box : m_boxes) //checks each box
	{
		if (box == nullptr) continue; //if not touching of the box it does nothing

		if (box->returnGlobalBounds().findIntersection(m_thiefSprite.getGlobalBounds())) //thief intersects with box
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

bool Thief::exit()
{
	return m_exit;
}

void Thief::loseLife(double dt)
{
	

	m_timer += dt;

	if (m_timer >= 3000)
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
int Thief::getPoints()
{
	return m_points;
}

sf::FloatRect Thief::returnBounds()
{
	return m_thiefSprite.getGlobalBounds();
}

void Thief::setItems(Items* items)
{
	m_items = items;
}
