#include "Game.h"
#include <iostream>

// Our target FPS
static float const FPS{ 60.0f };

////////////////////////////////////////////////////////////
Game::Game()
	:m_window(sf::VideoMode({ ScreenSize::s_width, ScreenSize::s_height },32), "Museum Heist", sf::Style::Default)
{
	init();
	
}

////////////////////////////////////////////////////////////
void Game::init()
{
	m_window.setVerticalSyncEnabled(true);
	if (!m_arialFont.openFromFile("ResourceFiles/font/akashi.ttf"))
	{
		std::cerr<< "error ";
	}

	m_thief.setBox(&m_itemOne);
	m_thief.setBox(&m_itemTwo);
	m_thief.setBox(&m_itemThree); //three boxes are stored and checked if collided with

	/*m_thief.addItem(&m_itemOne);
	m_thief.addItem(&m_itemTwo);
	m_thief.addItem(&m_itemThree);*/


	livesMessage.setFont(m_arialFont);
	livesMessage.setPosition(sf::Vector2f{ 1300, 40 });
	livesMessage.setCharacterSize(24);
	livesMessage.setFillColor(sf::Color::White);

	pointsMessage.setFont(m_arialFont);
	pointsMessage.setPosition(sf::Vector2f{ 1300, 80 });
	pointsMessage.setCharacterSize(24);
	pointsMessage.setFillColor(sf::Color::White);

	moneyMessage.setFont(m_arialFont);
	moneyMessage.setPosition(sf::Vector2f{ 420, 400 });
	moneyMessage.setCharacterSize(50);
	moneyMessage.setFillColor(sf::Color::White);

#ifdef TEST_FPS




	x_updateFPS.setFont(m_arialFont);
	x_updateFPS.setPosition(sf::Vector2f{20.0f,300.0f});
	x_updateFPS.setCharacterSize(24);
	x_updateFPS.setFillColor(sf::Color::White);
	//frames per second 
	x_drawFPS.setFont(m_arialFont);
	x_drawFPS.setPosition(sf::Vector2f{ 20.0f,350.0f });
	x_drawFPS.setCharacterSize(24);
	x_drawFPS.setFillColor(sf::Color::White);
	
#endif
	
}

////////////////////////////////////////////////////////////
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	sf::Time timePerFrame = sf::seconds(1.0f / FPS); // 60 fps


	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame.asMilliseconds()); //60 fps
#ifdef TEST_FPS
			x_secondTime += timePerFrame;
			x_updateFrameCount++;
			if (x_secondTime.asSeconds() > 1)
			{
				std::string updatesPS = "UPS " + std::to_string(x_updateFrameCount - 1);
				x_updateFPS.setString(updatesPS);
				std::string drawsPS = "DPS " + std::to_string(x_drawFrameCount);
				x_drawFPS.setString(drawsPS);
				x_updateFrameCount = 0;
				x_drawFrameCount = 0;
				x_secondTime = sf::Time::Zero;
			}
#endif
		}
		render(); // as many as possible
#ifdef TEST_FPS
		x_drawFrameCount++;
#endif
	}
}

////////////////////////////////////////////////////////////
void Game::processEvents()
{

	// get the next event from the event queue (if there is one)
	while (const std::optional event = m_window.pollEvent())
	{
		// "close requested" event: we close the window
		if (event->is<sf::Event::Closed>())
		{
			m_window.close();
		}
		if (event->is<sf::Event::KeyPressed>())
		{
			processKeyPressed(event);
		}
	}
}

////////////////////////////////////////////////////////////
void Game::processKeyPressed(const std::optional<sf::Event>& t_event)
{

	sf::Event::KeyPressed const* keyPressed = t_event->getIf<sf::Event::KeyPressed>();
	if (keyPressed != nullptr)
	{
		switch (keyPressed->code)
		{
		case sf::Keyboard::Key::Escape:
			m_window.close();
			break;
		default:
			break;
		}
	}


}

////////////////////////////////////////////////////////////
void Game::update(double dt)
{
	m_thief.update(dt);//updates the thief
	
		m_guard.update(dt, m_thief.getPosition());//updates the guard
		m_guardTwo.update(dt, m_thief.getPosition());
		m_guardThree.update(dt, m_thief.getPosition());

	
		m_scentTrail.update(dt, m_thief.getPosition());//updates the bubbles to the thiefs position

		m_cone.update(dt, m_guard.getPosition(), m_guard.getDirection());
		m_coneTwo.update(dt, m_guardTwo.getPosition(), m_guardTwo.getDirection());
		m_coneThree.update(dt, m_guardThree.getPosition(), m_guardThree.getDirection());//updates the guards vision cones

		m_itemOne.update(dt);
		m_itemTwo.update(dt);
		m_itemThree.update(dt);

		std::string livesMSG = "LIVES: " + std::to_string(m_thief.getLives());
		livesMessage.setString(livesMSG);
		

		std::string pointsMSG = "POINTS: " + std::to_string(m_thief.getPoints());
		pointsMessage.setString(pointsMSG);

		std::string moneyMSG = "CONGRATS!!\nyou earned: \n$" + std::to_string(m_thief.getPoints()) + ",000";
		moneyMessage.setString(moneyMSG);
}


////////////////////////////////////////////////////////////
void Game::render()
{
	m_window.clear(sf::Color(0, 0, 0, 0));
#ifdef TEST_FPS
	m_window.draw(m_bgSprite);//draws the background sprite (its on top so it draws under the other sprites) 
	m_window.draw(x_updateFPS);//updates fps message
	m_window.draw(x_drawFPS);//draws fps message
	

	

#endif

	
	m_thief.render(m_window);//draws the thief

	if (m_thief.exit())
	{
		m_window.draw(moneyMessage);
	}

	else if (m_thief.alive())
	{
		m_window.draw(livesMessage);//draws the thiefs lives
		m_window.draw(pointsMessage);//draws the total points the thief has

		m_guard.render(m_window);//draws the guards
		m_guardTwo.render(m_window);
		m_guardThree.render(m_window);

		m_scentTrail.render(m_window);//draws each bubble

		m_cone.render(m_window);
		m_coneTwo.render(m_window);
		m_coneThree.render(m_window); //draws the vision cones

		m_itemOne.render(m_window);
		m_itemTwo.render(m_window);
		m_itemThree.render(m_window);//draws the boxes holding the museme items

	}
	

		
	m_window.display();	
}

