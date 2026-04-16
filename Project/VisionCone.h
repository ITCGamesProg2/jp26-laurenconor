#pragma once
#include "Guard.h"
#include "ScreenSize.h"
#include <SFML/Graphics.hpp>
#include "ScentTrail.h"
#include <cmath>
#include <iostream>


class VisionCone {
public:
	VisionCone(Guard& guard, ScentTrail& trail, Thief& thief);
	void initCone(sf::Vector2f guardPos, GuardDirection dir);//get size, colour and position of bubbles
	//void leaveTrail();
	void update(double dt, sf::Vector2f guardPos, GuardDirection dir);//updates every 60th of a second
	void setConePos(double dt, sf::Vector2f guardPos,GuardDirection dir);//sets position of particles and gets the timer for each bubble
	void render(sf::RenderWindow& window);
	bool trailCollision();
	void handleCollision();
	void checkCollision();

	
//	void handleCollision();

private:
	sf::VertexArray m_cone;
	void updateConeDirection(sf::Vector2f guardPos, GuardDirection dir);

	Guard &m_guard;
	Thief& m_thief;
	ScentTrail& m_trail;
	enum class VisionState {SEARCHING, ALERT, PERSUING, ATTACKING};
	VisionState m_state{ VisionState::SEARCHING };
	sf::Color m_color;
	const int pointCount = 20;
	float fieldOfView = 40.0f;
	float startAngle = 0.0f;
	float const PI = 3.14159f;
	
};