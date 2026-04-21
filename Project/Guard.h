#pragma once
#include <SFML/Graphics.hpp>

enum class GuardDirection {LEFT,RIGHT,UP,DOWN};
enum class GuardMovement{LEFTRIGHT, UPDOWN};
class Guard
{
public:


	Guard(sf::Vector2f startPos = sf::Vector2f{ 600,70 }, GuardDirection startDir = GuardDirection::LEFT, GuardMovement movement = GuardMovement::LEFTRIGHT);
	
	void Guard::update(double dt, sf::Vector2f thiefPos);//updates the thief

	GuardDirection getDirection() const {
		return m_direction;
	};

	void Guard::render(sf::RenderWindow& window);//renders the sprite

	void Guard::movement();//getting the state formovement
	void Guard::LRMovement();//moving the guard left and right
	void Guard::UDMovement();
	//void Guard::UDMovement();// not yet used 

	bool Guard::movingLeft();
	bool Guard::movingDown();

	void Guard::initSprites(sf::Vector2f startPos);

	//sets and gets position
	void setPosition(sf::Vector2f t_position);
	sf::Vector2f getPosition() const;

	sf::FloatRect Guard::returnBounds();

	bool Guard::intersects(const sf::FloatRect& rect) const;

	void setChasing(bool chasing);
	void chaseTarget(sf::Vector2f targetPos, double dt);

void boundaryChecking();



private:
	
	bool left = true;
	bool down = true;

	bool m_isChasing = false;

	GuardDirection m_direction;//initalises the direction to left
	GuardMovement m_movement;//direction guard moves

	double m_speed{ 0.0f };//speed for guard
	sf::RectangleShape m_guard;//gets the basic rectangle shape

	sf::Texture m_guardTexture;
	sf::Sprite m_guardSprite{ m_guardTexture };
};

