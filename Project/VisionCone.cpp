#include "VisionCone.h"
#include "Guard.h"


VisionCone::VisionCone(Guard & guard) : m_guard(guard)
{
	initCone();//gets the position, size and colour of the bubbles
}

void VisionCone::update(double dt, sf::Vector2f guardPos)
{
	//leaveTrail();
	setConePos(dt,guardPos);//updates the bubbles to the thiefs position 
}

void VisionCone::setConePos(double dt, sf::Vector2f guardPos)//passes the time and the position of the thief
{
	m_cone.setPosition(sf::Vector2f{ guardPos.x + 15, guardPos.y + 35 });
	updateConeDirection();
}

void VisionCone::updateConeDirection()
{
	if (m_guard.movingLeft())
	{

		m_cone.setPoint(0, { 0.f,0.f });
		m_cone.setPoint(1, { -120.f,30.f });
		m_cone.setPoint(2, { -100.f,60.f });
		m_cone.setPoint(3, { -80.f,80.f });
		m_cone.setPoint(4, { -50.f,100.f });
		m_cone.setFillColor({ 255,255,102,155});
	}
	else
	{
		m_cone.setPoint(0, { 0.f,0.f });
		m_cone.setPoint(1, { 120.f,30.f });
		m_cone.setPoint(2, { 100.f,60.f });
		m_cone.setPoint(3, { 80.f,80.f });
		m_cone.setPoint(4, { 50.f,100.f });
		m_cone.setFillColor({ 255,255,102,155 });
	}

	/*if (m_guard.movingDown())
	{

	}*/

}

void VisionCone::initCone()
{
	m_cone.setPointCount(5);
	updateConeDirection();
		
}

void VisionCone::render(sf::RenderWindow& window)
{
	window.draw(m_cone);
}