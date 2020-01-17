/// <summary>
/// @author Dylan Curran and Greg Cahill
/// @date January 2020

/// </summary>

#include <iostream>
#include "include/Game.h"

/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode::getFullscreenModes()[0], "SFML window", sf::Style::Fullscreen },
	m_exitGame{false} //when true game will exit
{
	m_pred.init(sf::Vector2f(0,0));
	m_seeker.initSeeker(m_window);
	m_wanderer.initWander(m_window);
	setupFontAndText(); // load font 
	setupSprite(); // load texture
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	
	m_wanderer.update(t_deltaTime);
	m_pChar.update(t_deltaTime.asMilliseconds());
	m_pred.update(m_pChar.getPosition(),t_deltaTime.asMilliseconds());
	player_view.setCenter(m_pChar.getPosition());
	//m_window.setView(player_view);
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	
	m_window.clear();
	
	forLoopLibrary();
	m_window.setView(miniMap_view);
	m_window.draw(mapSprite);
	m_pChar.render(m_window);
	m_window.setView(player_view);
	m_seeker.render(m_window);

	m_wanderer.render(m_window);
	m_pChar.render(m_window);
	m_pred.render(m_window);
	m_window.display();
}

void Game::forLoopLibrary()
{
	for (int j = 0; j < 22; j++)
	{
		for (int i = 0; i < 40; i++)
		{
			
			m_window.setView(player_view);
			world.render(m_window, i, j);

			m_window.setView(miniMap_view);
			m_wanderer.render(m_window);
			m_pChar.render(m_window);
			world.render(m_window, i, j);
			m_window.setView(player_view);
			
		}
	}
	m_wanderer.render(m_window);
	m_pChar.render(m_window);
	m_window.display();
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("SFML Game");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(80U);
	m_welcomeMessage.setOutlineColor(sf::Color::Red);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

}

/// <summary>
/// load the texture and setup the sprite for the logo
/// </summary>
void Game::setupSprite()
{
	//miniMap_view.reset(sf::FloatRect(zeroVector, viewSize));
	
	world.init();
	miniMap_view.setSize(sf::Vector2f(m_window.getSize().x*1.8,m_window.getSize().y*2));
	miniMap_view.setViewport(sf::FloatRect(0.75f, 0, 0.25f, 0.25f));
	//miniMap_view.setViewport(sf::FloatRect(viewportOffset, viewportSize));
	m_pChar.movement(sf::Vector2f(m_window.getSize().x/2,m_window.getSize().y/2));
	default_view = sf::View(sf::FloatRect(0, 0, m_window.getSize().x, m_window.getSize().y));
	player_view=sf::View(sf::FloatRect(0, 0, m_window.getSize().x/2.5, m_window.getSize().y/2.5));
}
