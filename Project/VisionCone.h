#pragma once
#include "Guard.h"
#include "ScreenSize.h"
#include <SFML/Graphics.hpp>
#include "ScentTrail.h"
#include <cmath>
#include <iostream>


class VisionCone {
public:
	VisionCone(Guard& guard, ScentTrail& trail);
	void initCone(sf::Vector2f guardPos);//get size, colour and position of bubbles
	//void leaveTrail();
	void update(double dt, sf::Vector2f guardPos);//updates every 60th of a second
	void setConePos(double dt, sf::Vector2f guardPos);//sets position of particles and gets the timer for each bubble
	void render(sf::RenderWindow& window);
	//bool trailCollision();
	void handleCollision();

private:
	sf::VertexArray m_cone;
	void updateConeDirection(sf::Vector2f guardPos);

	Guard &m_guard;
	ScentTrail& m_trail;
	enum class VisionState {SEARCHING, ALERT, PERSUING, ATTACKING};
	VisionState m_state{ VisionState::PERSUING };
	sf::Color m_color;
	const int pointCount = 20;
	float fieldOfView = 40.0f;
	float startAngle = 0.0f;
	float const PI = 3.14159f;
	
};