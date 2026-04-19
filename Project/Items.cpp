#include "Items.h"
#include <iostream>

Items::Items(sf::Vector2f position) :m_jewlText("ResourceFiles/Images/jewleryOne.png"), m_crownText("ResourceFiles/Images/crown.png"),
m_spearText("ResourceFiles/Images/spear.png"), m_cloakText("ResourceFiles/Images/cloak.png"), m_butterfliesText("ResourceFiles/Images/butterflies.png")
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


	if (!m_spearText.loadFromFile("ResourceFiles/Images/spear.png"))
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_spearSprite.setPosition(sf::Vector2f{ 670,180 });
	m_spearSprite.setTexture(m_spearText);

	if (!m_cloakText.loadFromFile("ResourceFiles/Images/cloak.png"))
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_cloakSprite.setPosition(sf::Vector2f{ 120,330 });
	m_cloakSprite.setTexture(m_cloakText);

	if (!m_butterfliesText.loadFromFile("ResourceFiles/Images/butterflies.png"))
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_butterfliesSprite.setPosition(sf::Vector2f{ 800,180 });
	m_butterfliesSprite.setTexture(m_butterfliesText);


}
void Items::render(sf::RenderWindow& window)
{
	
	window.draw(m_box);
	window.draw(m_jewlSprite);
	window.draw(m_crownSprite);
	window.draw(m_spearSprite);
	window.draw(m_cloakSprite);
	window.draw(m_butterfliesSprite);

}



void Items::setPosition(sf::Vector2f t_position)//set position so we can use it in the gane
{
	m_box.setPosition(t_position);
}

sf::Vector2f Items::getPosition() const//gets positon so we can use it in the game
{
	return m_box.getPosition();
}

sf::FloatRect Items::returnGlobalBounds()
{
	return m_box.getGlobalBounds();
}