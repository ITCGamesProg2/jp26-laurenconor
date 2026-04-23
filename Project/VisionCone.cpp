#include "VisionCone.h"
#include "Guard.h"
#include "Thief.h"


VisionCone::VisionCone(Guard & guard, ScentTrail& trail, Thief& thief) : m_guard(guard), m_trail(trail),m_cone(sf::PrimitiveType::TriangleFan,20), m_thief(thief)
{
	initCone(guard.getPosition(), guard.getDirection(), startAngle);//gets the position, size and colour of the bubbles
}

void VisionCone::update(double dt, sf::Vector2f guardPos, GuardDirection dir)
{
		checkCollision(dt);//chacks collision with scent trail
		handleCollision();//changes st
		
		if (m_state == VisionState::SEARCHING || m_state == VisionState::ALERT)//updates cone based on the guards position and angle to player 
		{
			updateConeDirection(guardPos, directionToAngle(dir));
		}
}



void VisionCone::updateConeDirection(sf::Vector2f guardPos, float angle)
{

	
	sf::Vector2f origin = { guardPos.x + 8.0f,guardPos.y + 75.0f };

	const float step = fieldOfView / pointCount;
	m_cone.setPrimitiveType(sf::PrimitiveType::TriangleFan);
	m_cone.resize(pointCount);
	m_cone[0].position = origin;
	m_cone[0].color = m_color;

	for (int i = 0; i <= pointCount - 2; ++i)
	{
		float a= (angle + i * step) * PI / 180.0f;
		float x = origin.x + std::cos(a) * 200;
		float y = origin.y + std::sin(a) * 200;
		m_cone[i + 1].position = { x,y };
		m_cone[i + 1].color = m_color;
	}

}

float VisionCone::directionToAngle(GuardDirection dir)
{
	switch (dir)
	{
	case GuardDirection::LEFT:
		return  (180 - (fieldOfView / 2.0f));//points cone left
		break;
	case GuardDirection::RIGHT:
		return  (0 - (fieldOfView / 2.0f));//points cone right
		break;
	case GuardDirection::DOWN:
		return (90 - (fieldOfView / 2.0f));//points cone down
		break;
	case GuardDirection::UP:
		return (270 - (fieldOfView / 2.0f));//points cone up
		break;
	}
	return 0.0f;
}

void VisionCone::initCone(sf::Vector2f guardPos, GuardDirection dir,float startingAngle)
{
	
	updateConeDirection(guardPos, directionToAngle(dir));//draws the cone in the position guard is facing
		
}

void VisionCone::render(sf::RenderWindow& window)//draws cone on screen
{
	window.draw(m_cone);
}

bool VisionCone::trailCollision()//if cone intersects with the trail
{
	return m_trail.intersects(m_cone.getBounds());
}

void VisionCone::handleCollision()//if collision
{
	if (m_state == VisionState::SEARCHING)//no collision with thief
	{
		m_color = { 102,255,102,155 };//colour is green
	}
	else if (m_state == VisionState::ALERT)//scent trail is colliding with cone
	{
		m_color = { 255,255,102,155 };//colour is yelllow
	}
	else if (m_state == VisionState::PERSUING)//scent trail is colliding with guard
	{
		m_color = { 255,152,102,155 };//colour is orange 
	}
	else if(m_state == VisionState::ATTACKING)//thief and guard collision
	{ 
		m_color = { 255,0,0,155 };//colour is red
	}
}

void VisionCone::checkCollision(double dt)//checks collision
{
	m_state = VisionState::SEARCHING;//if no collison set to searching
	m_guard.setChasing(false);//set chasing set to false

	if (trailCollision())//scent trail is colliding with cone
	{
		m_state = VisionState::ALERT;
		
	}
	if (m_trail.intersects(m_guard.returnBounds()))//scent trail is colliding with guard
	{
		m_guard.setChasing(true);
		m_state = VisionState::PERSUING;

		sf::Vector2f diff = m_thief.getPosition() - m_guard.getPosition();
		float angleRad = std::atan2(diff.y, diff.x);
		float angleDeg = angleRad * (180.0f/ PI);
		startAngle = angleDeg - (fieldOfView / 2.0f);
		
		updateConeDirection(m_guard.getPosition(), startAngle);
		
		
	}
	else {
		m_guard.setChasing(false);
	}
	if (m_guard.intersects(m_thief.returnBounds()))//thief and guard collision
	{
		m_state = VisionState::ATTACKING;
		m_thief.loseLife(dt);
	}

}
