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


	sf::FloatRect retJewlBounds();
	sf::FloatRect retCrownBounds();
	sf::FloatRect retSpearBounds();
	sf::FloatRect retCloakBounds();
	sf::FloatRect retButBounds();

	bool m_jewlVisible = true;
	bool m_crownVisible = true;
	bool m_spearVisible = true;
	bool m_cloakVisible = true;
	bool m_butVisible = true;

	void setJewlVisible(bool jewlVisible);
	void setCrownVisible(bool crownVisible);
	void setSpearVisible(bool spearVisible);
	void setCloakVisible(bool cloakVisible);
	void setButVisible(bool butVisible);

	bool getJewlVisible() const;
	bool getCrownlVisible() const;
	bool getSpearVisible() const;
	bool getCloakVisible() const;
	bool getButVisible() const;

	//bool jewlVisible = true;


private:

	sf::Texture m_jewlText;
	sf::Sprite m_jewlSprite{ m_jewlText };

	sf::Texture m_crownText;
	sf::Sprite m_crownSprite{ m_crownText };

	sf::Texture m_spearText;
	sf::Sprite m_spearSprite{ m_spearText };

	sf::Texture m_cloakText;
	sf::Sprite m_cloakSprite{ m_cloakText };

	sf::Texture m_butterfliesText;
	sf::Sprite m_butterfliesSprite{ m_butterfliesText };

	
	sf::RectangleShape m_box;//gets the rectangle shape for the box for jewlery

};

