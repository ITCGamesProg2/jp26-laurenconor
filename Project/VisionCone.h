#pragma once
#include "Guard.h"
#include "ScreenSize.h"
#include <iostream>


class VisionCone {
public:
	VisionCone();
	void initCone();//get size, colour and position of bubbles
	//void leaveTrail();
	void update(double dt, sf::Vector2f thiefPos);//updates every 60th of a second
	//void setConePos(double dt, sf::Vector2f thiefPos);//sets position of particles and gets the timer for each bubble
	void render(sf::RenderWindow& window);

private:
	
	sf::CircleShape m_cone{ 80.0f,3 };//the shape for the vision cone - takes 3 points one for each corner
	
};