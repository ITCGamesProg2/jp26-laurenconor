#pragma once
#include <SFML/Graphics.hpp>


class Items
{
public:

	Items(sf::Vector2f t_position);

	void Items::update(double dt);//updates the thief

	void Items::initSprites(sf::Vector2f position);//gets the basic shaoe for the thief

	void Items::render(sf::RenderWindow& window);//renders the sprite
	void Items::handleKeyInput();//for movement

	//gets and sets position to be used by the scentTrail class
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

	sf::FloatRect Items::returnGlobalBounds();

	//gets bounds for each shape
	sf::FloatRect retJewlBounds();
	sf::FloatRect retCrownBounds();
	sf::FloatRect retSignBounds();
	sf::FloatRect retCloakBounds();
	sf::FloatRect retButBounds();
	sf::FloatRect retBookBounds();
	sf::FloatRect retHatBounds();
	sf::FloatRect retWeaponsBounds();

	//initialising bool for visible items
	bool m_jewlVisible = true;
	bool m_crownVisible = true;
	bool m_signVisible = true;
	bool m_cloakVisible = true;
	bool m_butVisible = true;
	bool m_bookVisible = true;
	bool m_hatVisible = true;
	bool m_weaponsVisible = true;

	//sets bool for visible items
	void setJewlVisible(bool jewlVisible);
	void setCrownVisible(bool crownVisible);
	void setSignVisible(bool spearVisible);
	void setCloakVisible(bool cloakVisible);
	void setButVisible(bool butVisible);
	void setBookVisible(bool bookvisible);
	void setHatVisible(bool hatVisible);
	void setWeaponsVisible(bool weaponsVisible);

	//gets bool for visible items
	bool getJewlVisible() const;
	bool getCrownVisible() const;
	bool getSignVisible() const;
	bool getCloakVisible() const;
	bool getButVisible() const;
	bool getBookVisible() const;
	bool getHatVisible() const;
	bool getWeaponsVisible() const;

	//bool jewlVisible = true;


private:

	//sprites and textures for each item
	sf::Texture m_jewlText;
	sf::Sprite m_jewlSprite{ m_jewlText };

	sf::Texture m_crownText;
	sf::Sprite m_crownSprite{ m_crownText };

	sf::Texture m_signText;
	sf::Sprite m_signSprite{ m_signText };

	sf::Texture m_cloakText;
	sf::Sprite m_cloakSprite{ m_cloakText };

	sf::Texture m_butterfliesText;
	sf::Sprite m_butterfliesSprite{ m_butterfliesText };

	sf::Texture m_bookText;
	sf::Sprite m_bookSprite{ m_bookText };
	
	sf::Texture m_hatText;
	sf::Sprite m_hatSprite{ m_hatText };

	sf::Texture m_weaponsText;
	sf::Sprite m_weaponsSprite{ m_weaponsText };

	sf::RectangleShape m_box;//gets the rectangle shape for the box for jewlery

};

