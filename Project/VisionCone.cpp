#include "VisionCone.h"
#include "Guard.h"
#include "Thief.h"


VisionCone::VisionCone(Guard & guard, ScentTrail& trail, Thief& thief) : m_guard(guard), m_trail(trail),m_cone(sf::PrimitiveType::TriangleFan,20), m_thief(thief)
{
	initCone(guard.getPosition());//gets the position, size and colour of the bubbles
}

void VisionCone::update(double dt, sf::Vector2f guardPos)
{
	//leaveTrail();
	setConePos(dt,guardPos);//updates the bubbles to the thiefs position 
	/*if (trailCollision())
	{*/
		handleCollision();
		updateConeDirection(guardPos);
		checkCollision();
	//}
}

void VisionCone::setConePos(double dt, sf::Vector2f guardPos)//passes the time and the position of the thief
{
	//m_cone.setPosition(sf::Vector2f{ guardPos.x + 15, guardPos.y + 35 });
	updateConeDirection(guardPos);
}

void VisionCone::updateConeDirection(sf::Vector2f guardPos)
{
	m_cone[0].color = m_color;
	if (m_guard.movingLeft())
	{
		startAngle = (180 - (fieldOfView / 2.0f));
	}
	if (!m_guard.movingLeft())
	{
		startAngle = (0 - (fieldOfView / 2.0f));
	}
	const float step = fieldOfView / pointCount;
	m_cone.setPrimitiveType(sf::PrimitiveType::TriangleFan);
	m_cone.resize(pointCount);
	m_cone[0].position = { sf::Vector2f{guardPos.x + 15, guardPos.y + 35} };
	
	for (int i = 0; i <= pointCount - 2; ++i)
	{
		float angle = (startAngle + i * step) * PI / 180.0f;
		float x = guardPos.x + std::cos(angle) * 200;
		float y = guardPos.y + std::sin(angle) * 200;

		m_cone[i + 1].position = { x,y };
		m_cone[i + 1].color = m_color;
	}

}

void VisionCone::initCone(sf::Vector2f guardPos)
{
	//m_cone.setPointCount(5);
	updateConeDirection(guardPos);
		
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

void VisionCone::checkCollision()
{
	if (trailCollision())
	{
		m_state = VisionState::ALERT;
	}
	if (m_trail.intersects(m_guard.returnBounds()))
	{
		m_guard.setChasing(true);
		m_state = VisionState::PERSUING;
	}
	else {
		m_guard.setChasing(false);
	}
	if (m_guard.intersects(m_thief.returnBounds()))
	{
		m_state = VisionState::ATTACKING;
	}

}
