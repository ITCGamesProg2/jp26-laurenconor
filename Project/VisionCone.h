#pragma once
#include "Guard.h"
#include "ScreenSize.h"
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


class VisionCone {
public:
	VisionCone(Guard& guard);
	void initCone();//get size, colour and position of bubbles
	//void leaveTrail();
	void update(double dt, sf::Vector2f guardPos);//updates every 60th of a second
	void setConePos(double dt, sf::Vector2f guardPos);//sets position of particles and gets the timer for each bubble
	void render(sf::RenderWindow& window);
	
private:
	sf::ConvexShape m_cone;
	void updateConeDirection();

	Guard &m_guard;
	
};