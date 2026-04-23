#include "Items.h"
#include <iostream>

Items::Items(sf::Vector2f position) :m_jewlText("ResourceFiles/Images/jewleryOne.png"), m_crownText("ResourceFiles/Images/crown.png"),
m_signText("ResourceFiles/Images/sign.png"), m_cloakText("ResourceFiles/Images/cloak.png"), m_butterfliesText("ResourceFiles/Images/butterflies.png"), m_bookText("ResourceFiles/Images/book.png"),m_hatText("ResourceFiles/Images/hat.png"),m_weaponsText("ResourceFiles/Images/weapons.png")
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
	m_box.setPosition(sf::Vector2f{ position });//gets rectangle for the boxes


	if (!m_jewlText.loadFromFile("ResourceFiles/Images/jewleryOne.png"))//sets images for item
	{
		std::cout << "file not loading properly" << std::endl; 
	}
	m_jewlSprite.setPosition(sf::Vector2f{ 450,320 });//sets position for item
	m_jewlSprite.setScale(sf::Vector2f{ 2, 2});//sets scale for item
	m_jewlSprite.setTexture( m_jewlText);//sets texture for item

	if (!m_crownText.loadFromFile("ResourceFiles/Images/crown.png"))//sets images for item
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_crownSprite.setPosition(sf::Vector2f{ 300,330 });//sets position for item
	m_crownSprite.setScale(sf::Vector2f{ 2, 2 });//sets scale for item
	m_crownSprite.setTexture(m_crownText);//sets texture for item


	if (!m_signText.loadFromFile("ResourceFiles/Images/sign.png"))//sets images for item
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_signSprite.setPosition(sf::Vector2f{ 1300,800 });//sets position for item
	m_signSprite.setTexture(m_signText);//sets texture for item

	if (!m_cloakText.loadFromFile("ResourceFiles/Images/cloak.png"))//sets images for item
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_cloakSprite.setPosition(sf::Vector2f{ 120,330 });//sets position for item
	m_cloakSprite.setTexture(m_cloakText);//sets texture for item

	if (!m_butterfliesText.loadFromFile("ResourceFiles/Images/butterflies.png"))//sets images for item
	{
		std::cout << "file not loading properly" << std::endl;
	}
	m_butterfliesSprite.setPosition(sf::Vector2f{ 820,170 });//sets position for item
	m_butterfliesSprite.setScale(sf::Vector2f{ 1.5, 1.5 });//sets scale for item
	m_butterfliesSprite.setTexture(m_butterfliesText);//sets texture for item

	if (!m_bookText.loadFromFile("ResourceFiles/Images/book.png"))//sets images for item
	{
		std::cout << "book not loading properly" << std::endl;
	}
	m_bookSprite.setPosition(sf::Vector2f(990, 150));//sets position for item
	m_bookSprite.setTexture(m_bookText);//sets texture for item

	if (!m_hatText.loadFromFile("ResourceFiles/Images/hat.png"))//sets images for item
	{
		std::cout << "hat not loading properly" << std::endl;
	}
	m_hatSprite.setPosition(sf::Vector2f(450, 650));//sets position for item
	m_hatSprite.setTexture(m_hatText);//sets texture for item

	if (!m_weaponsText.loadFromFile("ResourceFiles/Images/weapons.png"))//sets images for item
	{
		std::cout << "weapons not loading properly" << std::endl;
	}
	m_weaponsSprite.setPosition(sf::Vector2f(650, 650));//sets position for item
	m_weaponsSprite.setTexture(m_weaponsText);//sets texture for item

}

void Items::render(sf::RenderWindow& window)
{
	
	window.draw(m_box);
	if (m_jewlVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_jewlSprite);//draws sprite
	}
	if (m_crownVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_crownSprite);//draws sprite
	}
	if (m_signVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_signSprite);//draws sprite
	}
	if (m_cloakVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_cloakSprite);//draws sprite
	}
	if (m_butVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_butterfliesSprite);//draws sprite
	}
	if(m_bookVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_bookSprite);//draws sprite
	}
	if (m_hatVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_hatSprite);//draws sprite
	}
	if (m_weaponsVisible)// if item is alive/ player has not intersected
	{
		window.draw(m_weaponsSprite);//draws sprite
	}

}



void Items::setPosition(sf::Vector2f t_position)//set position so we can use it in the gane
{
	m_box.setPosition(t_position);
}

sf::Vector2f Items::getPosition() const//gets positon so we can use it in the game
{
	return m_box.getPosition();
}

sf::FloatRect Items::returnGlobalBounds()//return bounds for collision checking
{
	return m_box.getGlobalBounds();
}



//return bounds for collision checking in thief
sf::FloatRect Items::retJewlBounds()
{
	return m_jewlSprite.getGlobalBounds();
}

sf::FloatRect Items::retCrownBounds()
{
	return m_crownSprite.getGlobalBounds();
}

sf::FloatRect Items::retSignBounds()
{
	return m_signSprite.getGlobalBounds();
}

sf::FloatRect Items::retCloakBounds()
{
	return m_cloakSprite.getGlobalBounds();
}

sf::FloatRect Items::retButBounds()
{
	return m_butterfliesSprite.getGlobalBounds();
}
sf::FloatRect Items::retBookBounds()
{
	return m_bookSprite.getGlobalBounds();
}

sf::FloatRect Items::retHatBounds()
{
	return m_hatSprite.getGlobalBounds();
}

sf::FloatRect Items::retWeaponsBounds()
{
	return m_weaponsSprite.getGlobalBounds();
}


//sets the bool to false if player has collided with items
void Items::setJewlVisible(bool jewlVisible)
{
	m_jewlVisible = jewlVisible;
	if(!jewlVisible)
	{
		m_jewlSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}

void Items::setCrownVisible(bool crownVisible)
{
	m_crownVisible = crownVisible;
	if (!crownVisible)
	{
		m_crownSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}

void Items::setSignVisible(bool signVisible)
{
	m_signVisible = signVisible;
	
}

void Items::setCloakVisible(bool cloakVisible)
{
	m_cloakVisible = cloakVisible;
	if (!cloakVisible)
	{
		m_cloakSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}

void Items::setButVisible(bool butVisible)
{
	m_butVisible = butVisible;
	if (!butVisible)
	{
		m_butterfliesSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}

void Items::setBookVisible(bool bookVisible)
{
	m_bookVisible = bookVisible;
	if (!bookVisible)
	{
		m_bookSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}

void Items::setHatVisible(bool hatVisible)
{
	m_hatVisible = hatVisible;
	if (!hatVisible)
	{
		m_hatSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}

void Items::setWeaponsVisible(bool weaponsVisible)
{
	m_weaponsVisible = weaponsVisible;
	if (!weaponsVisible)
	{
		m_weaponsSprite.setPosition(sf::Vector2f{ -100,-100 });
	}
}



bool Items::getJewlVisible() const
{
	return m_jewlVisible;
}

bool Items::getCrownVisible() const
{
	return m_crownVisible;
}

bool Items::getSignVisible() const
{
	return m_signVisible;
}

bool Items::getCloakVisible() const
{
	return m_cloakVisible;
}

bool Items::getButVisible() const
{
	return m_butVisible;
}

bool Items::getBookVisible() const
{
	return m_bookVisible;
}

bool Items::getHatVisible() const
{
	return m_hatVisible;
}

bool Items::getWeaponsVisible() const
{
	return m_hatVisible;
}
