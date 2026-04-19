#include "VisionCone.h"
#include "Guard.h"
#include "Thief.h"


VisionCone::VisionCone(Guard & guard, ScentTrail& trail, Thief& thief) : m_guard(guard), m_trail(trail),m_cone(sf::PrimitiveType::TriangleFan,20), m_thief(thief)
{
	initCone(guard.getPosition(), guard.getDirection(), startAngle);//gets the position, size and colour of the bubbles
}

void VisionCone::update(double dt, sf::Vector2f guardPos, GuardDirection dir)
{
		checkCollision(dt);
		handleCollision();//changes st
		
		if (m_state == VisionState::SEARCHING || m_state == VisionState::ALERT)
		{
			updateConeDirection(guardPos, directionToAngle(dir));
		}
}



void VisionCone::updateConeDirection(sf::Vector2f guardPos, float angle)
{

	
	sf::Vector2f origin = { guardPos.x + 15.0f,guardPos.y + 35.0f };

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
		return  (180 - (fieldOfView / 2.0f));
		break;
	case GuardDirection::RIGHT:
		return  (0 - (fieldOfView / 2.0f));
		break;
	case GuardDirection::DOWN:
		return (90 - (fieldOfView / 2.0f));
		break;
	case GuardDirection::UP:
		return (270 - (fieldOfView / 2.0f));
		break;
	}
	return 0.0f;
}

void VisionCone::initCone(sf::Vector2f guardPos, GuardDirection dir,float startingAngle)
{
	
	updateConeDirection(guardPos, directionToAngle(dir));
		
}

void VisionCone::render(sf::RenderWindow& window)
{
	window.draw(m_cone);
}

bool VisionCone::trailCollision()
{
	return m_trail.intersects(m_cone.getBounds());
}

void VisionCone::handleCollision()
{
	if (m_state == VisionState::SEARCHING)
	{
		m_color = { 102,255,102,155 };
	}
	else if (m_state == VisionState::ALERT)
	{
		m_color = { 255,255,102,155 };
	}
	else if (m_state == VisionState::PERSUING)
	{
		m_color = { 255,152,102,155 };
	}
	else if(m_state == VisionState::ATTACKING)
	{ 
		m_color = { 255,0,0,155 };
	}
}

void VisionCone::checkCollision(double dt)
{
	m_state = VisionState::SEARCHING;
	m_guard.setChasing(false);

	if (trailCollision())
	{
		m_state = VisionState::ALERT;
		
	}
	if (m_trail.intersects(m_guard.returnBounds()))
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
	if (m_guard.intersects(m_thief.returnBounds()))
	{
		m_state = VisionState::ATTACKING;
		m_thief.loseLife(dt);
	}

}
