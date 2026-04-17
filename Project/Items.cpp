#include "Items.h"
#include <iostream>

Items::Items(sf::Vector2f position) :m_jewlText("ResourceFiles/Images/jewleryOne.png")
{
	initSprites(position);
}

void Items::update(double dt)
{
	//handleKeyInput();
}

void Items::initSprites(sf::Vector2f position)//gets the basic colours for the rectangle so i can visualise what is going on even without the proper sprite
{
	m_box.setFillColor({ 153, 102, 51 });
	m_box.setSize(sf::Vector2f{ 450,75 });
	m_box.setPosition(sf::Vector2f{ position });


	if (!m_jewlText.loadFromFile("ResourceFiles/Images/jewleryOne.png"))
	{
		std::cout << "file not loading properly" << std::endl; 
	}
	m_jewlSprite.setPosition(sf::Vector2f{ 450,350 });
	m_jewlSprite.setTexture( m_jewlText);

	if (!m_crownText.loadFromFile("ResourceFiles/Images/crown.png"))
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_crownSprite.setPosition(sf::Vector2f{ 300,360 });
	m_crownSprite.setTexture(m_crownText);



}
void Items::render(sf::RenderWindow& window)
{
	
	window.draw(m_box);
	window.draw(m_jewlSprite);
	window.draw(m_crownSprite);

}



void Items::setPosition(sf::Vector2f t_position)//set position so we can use it in the gane
{
	m_box.setPosition(t_position);
}

sf::Vector2f Items::getPosition() const//gets positon so we can use it in the game
{
	return m_box.getPosition();
}

