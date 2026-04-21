#pragma once
#include "Thief.h"
#include "ScreenSize.h"
#include <iostream>


class ScentTrail {
public:
	ScentTrail();
	void initParticles();//get size, colour and position of bubbles
//void leaveTrail();
	void update(double dt, sf::Vector2f thiefPos);//updates every 60th of a second
	void setParticlePos(double dt, sf::Vector2f thiefPos);//sets position of particles and gets the timer for each bubble
	void render(sf::RenderWindow& window);
	//sf::FloatRect globalBounds();
	bool intersects(const sf::FloatRect& rect) const;


	float retAlpha();
	

private:
	float alpha = 0.0f;
	static const int TOTAL_PARTICLES = 6;//set the total number of particles
	sf::CircleShape m_particles[TOTAL_PARTICLES];// = TOTAL_PARTICLES; //get the total number of particles
	float m_particleLifetime[TOTAL_PARTICLES];//gets lifetime of each bubble
	const float MAX_LIFETIME = 4.0f;//max lifetime for each bubble might change to 3.5 because 3 is too fast and 4 might be too slow..
	
	

	//sf::CircleShape m_bubble;
};