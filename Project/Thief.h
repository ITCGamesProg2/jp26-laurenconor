#pragma once
#include <SFML/Graphics.hpp>
#include "Items.h"

class Thief 
{
public:

	Thief();

	void Thief::update(double dt);//updates the thief

	void Thief::initSprites();//gets the basic shaoe for the thief

	void Thief::render(sf::RenderWindow& window);//renders the sprite
	void Thief::handleKeyInput();//for movement

	//gets and sets position to be used by the scentTrail class
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;
	void boundChecking();
	
	bool wallChecking();
	void setBox(Items* box);

	bool alive();
	bool m_alive = true;
	
	void loseLife(double dt);
	int getLives() const;

	sf::FloatRect Thief::returnBounds();
	
	float const TOTAL_LIVES = 3;
	float m_lives = TOTAL_LIVES;
	float m_timer{ 0.0f };

	void setItems(Items* items);

	sf::Texture m_thiefTexture;
	sf::Sprite m_thiefSprite{ m_thiefTexture };

private:

	std::vector<Items*> m_boxes;

	Items* m_items;//{nullptr}
	double m_speed{ 0.0f };//speed for thief
	sf::RectangleShape m_thief;//gets the rectangle shape for the thief

};
