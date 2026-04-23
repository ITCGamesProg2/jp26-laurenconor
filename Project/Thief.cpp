#include "Thief.h"
#include <iostream>

Thief::Thief()
{
	m_items = new Items(sf::Vector2f{ 0,0 });
	initSprites();
}

void Thief::update(double dt)
{
	handleKeyInput();//key presses
	boundChecking();//checks player bounds so it dosent go off screen
}



void Thief::initSprites()
{
	if (!m_thiefTexture.loadFromFile("ResourceFiles/Images/thief_crouch.png"))//thief sprite
	{
		std::cout << "error loading thief sprite" << std::endl;
	}
	
	
	m_thiefSprite = sf::Sprite{ m_thiefTexture };//setting texture
	m_thiefSprite.setTextureRect(sf::IntRect({ 15,3 }, { 30, 67 }));//getting specific sprite
	m_thiefSprite.setScale(sf::Vector2f{ 2,2 });//setting scale
	m_thiefSprite.setPosition(sf::Vector2f{ 10,70 });//setting position


}
void Thief::render(sf::RenderWindow& window)
{
	//window.draw(m_thief);
	window.draw(m_thiefSprite);//drawing sprite
}

void Thief::handleKeyInput()//gets the key inputs and moves it in the direction the player wants
{
	sf::Vector2f pos = m_thiefSprite.getPosition();//getting vector for position
	

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
			m_thiefSprite.setPosition(pos);//setting the new position to the old one if sprite collides with wall so it dosent go into the wall
		}
	
		for (Items* item : m_boxes)//goes through the items in the items class
		{
			if (item == nullptr) continue;//if the item is empty it moves onto the next one
			if (item->retCloakBounds().findIntersection(m_thiefSprite.getGlobalBounds()))//checking if the item intersects with the thief
			{
				if (m_items->getCloakVisible())//checks if item is visible
				{
					item->setCloakVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
				}
			}
			if (item->retCrownBounds().findIntersection(m_thiefSprite.getGlobalBounds()))//checking if the item intersects with the thief
			{
				if (m_items->getCrownVisible())//checks if item is visible
				{
					item->setCrownVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
				}
			}
			if (item->retJewlBounds().findIntersection(m_thiefSprite.getGlobalBounds()))//checking if the item intersects with the thief
			{
				if (m_items->getJewlVisible())//checks if item is visible
				{
					item->setJewlVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
				}
			}
			if (item->retSignBounds().findIntersection(m_thiefSprite.getGlobalBounds()) )//checking if the item intersects with the thief
			{
				m_exit = true;//if thief intersects with exit sign game is over
			}
			if (item->retButBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getButVisible())//checking if the item intersects with the thief
			{
				if (m_items->getButVisible())//checks if item is visible
				{
					item->setButVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
				}

			}
			if (item->retBookBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getBookVisible())//checking if the item intersects with the thief
			{
				if (m_items->getBookVisible())//checks if item is visible
				{
					item->setBookVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
				}
			}
			if (item->retHatBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getHatVisible())//checking if the item intersects with the thief
			{
				if (m_items->getHatVisible())//checks if item is visible
				{
					item->setHatVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
				}
			}
			if (item->retWeaponsBounds().findIntersection(m_thiefSprite.getGlobalBounds()) && m_items->getWeaponsVisible())//checking if the item intersects with the thief
			{
				if (m_items->getWeaponsVisible())//checks if item is visible
				{
					item->setWeaponsVisible(false);//returns false to stop drawing the item in the items class
					m_points += 5;//add points
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

void Thief::boundChecking()//checking the edge of the screen so the thief dosent go past it
{

	if (m_thiefSprite.getPosition().x <= 0)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ 0, getPosition().y });//left
		
	}
	else if (m_thiefSprite.getPosition().x + 30 >= 1440)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ 1410, getPosition().y });//right
	}

	else if (m_thiefSprite.getPosition().y <= 0)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ getPosition().x, 0});//top
	}

	else if (m_thiefSprite.getPosition().y + 70 >= 900)
	{
		m_thiefSprite.setPosition(sf::Vector2f{ getPosition().x, 830 });//bottom
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
	m_boxes.push_back(box);//pushes thief back from item
}

bool Thief::alive()
{
	if (m_lives > 0)
	{
		m_alive = true;//if lives are greater than 0 thief is alive
	}
	else
	{
		return false;
	}
}

bool Thief::exit()
{
	return m_exit;//if exit box had been intersected with
}

void Thief::loseLife(double dt)//looses thief life if guard intersects with it
{
	
	m_timer += dt;

	if (m_timer >= 3000)
	{
		m_lives -= 1;
		m_timer = 0.0f;
		std::cout << "remianing lives: " << m_lives;
	}

}

int Thief::getLives() const//gets lives to display on screen
{
	return m_lives;
}
int Thief::getPoints()//gets points to display on screen
{
	return m_points;
}

sf::FloatRect Thief::returnBounds()//returns player bounds
{
	return m_thiefSprite.getGlobalBounds();
}

void Thief::setItems(Items* items)//gets item player is checking through
{
	m_items = items;
}
