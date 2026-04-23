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

	bool alive();//returns alive
	bool m_alive = true;
	bool exit();//returns exit if player collides with exit sign
	bool m_exit = false;
	
	void loseLife(double dt);//looses lives when colliding with guard
	int getLives() const;//gets lives to return to game class for livesMessage

	sf::FloatRect Thief::returnBounds();//returns bounds for collision checking
	
	float const TOTAL_LIVES = 3;//const for total lives
	float m_lives = TOTAL_LIVES;//sets total lives
	float m_timer{ 0.0f };//timer

	void setItems(Items* items);//checks through the items in the items class

	int getPoints();//get points when collides with items

	sf::Texture m_thiefTexture;
	sf::Sprite m_thiefSprite{ m_thiefTexture };//sets the texture and sprite for the thief

private:

	int m_points = 0;//initalises points for thief

	std::vector<Items*> m_boxes;//vector for the items thief has to check through

	Items* m_items;//{nullptr}
	double m_speed{ 0.0f };//speed for thief
	sf::RectangleShape m_thief;//gets the rectangle shape for the thief

};
