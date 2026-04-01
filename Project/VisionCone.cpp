#include "VisionCone.h"


VisionCone::VisionCone()
{
	initCone();//gets the position, size and colour of the bubbles
}

void VisionCone::update(double dt, sf::Vector2f thiefPos)
{
	//leaveTrail();
	//setConePos(/*dt*/);//updates the bubbles to the thiefs position 
}

//void VisionCone::setConePos(/*double dt*/ )//passes the time and the position of the thief
//{
//	
//		
//}

void VisionCone::initCone()
{
	m_cone.setFillColor({ 100,100,100,100 });
	m_cone.setPosition(sf::Vector2f{ 200,500 });
}

void VisionCone::render(sf::RenderWindow& window)
{
	window.draw(m_cone);
}