#include "ScentTrail.h"


ScentTrail::ScentTrail()
{
	initParticles();//gets the position, size and colour of the bubbles
}

void ScentTrail::update(double dt, sf::Vector2f thiefPos)
{
	//leaveTrail();
	setParticlePos(dt, thiefPos);//updates the bubbles to the thiefs position 
}

void ScentTrail::setParticlePos(double dt, sf::Vector2f thiefPos)//passes the time and the position of the thief
{
	for (int parNum = 0; parNum < TOTAL_PARTICLES; parNum++)//loops through the array of bubbles / particles
	{

		m_particleLifetime[parNum] -= dt / 1000.0f;//gets the seconds 

		if (m_particleLifetime[parNum] <= 0)//if the bubble fades away(timer runs out & has faded properly)
		{
			m_particleLifetime[parNum] = MAX_LIFETIME;//gets the lifetime for each bubble
			m_particles[parNum].setPosition(thiefPos);//sets the position to the thiefs position
			m_particles[parNum].setFillColor(sf::Color::White);//resets color to white when it respawns since the colour had faded 
		}

		
		float time = m_particleLifetime[parNum] / MAX_LIFETIME; //divides the seconds the specific bubble has been alive and divides it by the max lifetime of a bubble
		sf::Color col = m_particles[parNum].getFillColor();//gets the fill colour of the bubble
		col.a = static_cast<unsigned char>(time * 255.0f);//we reduce the colours alpha on the bubble overtime 
		m_particles[parNum].setFillColor(col);//sets the new color to the specific bubble

	}
}

void ScentTrail::initParticles()
{
	for (int parNum = 0; parNum < TOTAL_PARTICLES; parNum++)
	{
		m_particles[parNum].setFillColor({ sf::Color::White });//gets the colour of the bubble at the start of its life
		m_particles[parNum].setPosition({400,70});//makes sure the bubble starts exactly where the thief/ player starts
		m_particles[parNum].setRadius(10.0f);//sets radius/ size of bubble 
		m_particleLifetime[parNum] = MAX_LIFETIME* ((float)parNum / TOTAL_PARTICLES);//to get the remainding lifetime of a specific bubble we multiply the max 
																					 //lifetime by the specific bubble divided by the total particles (starts the timer)
	}
}

void ScentTrail::render(sf::RenderWindow& window)
{
	for (int parNum = 0; parNum < TOTAL_PARTICLES; parNum++)
	{
		window.draw(m_particles[parNum]);//draws the individual bubbles
	}
}

bool ScentTrail::intersects(const sf::FloatRect& rect) const
{
	std::cout << "Checking"<<std::endl;
	for (int parNum = 0; parNum < TOTAL_PARTICLES; parNum++)
	{
		std::cout << "for loop" << std::endl;
		if (m_particles[parNum].getFillColor().a == 0)
		{	
			continue;
		}
		if (m_particles[parNum].getGlobalBounds().findIntersection(rect))
		{
			std::cout << "there is collision Checking" << std::endl;
			return true;
		}

	}
	
	return false;
}

