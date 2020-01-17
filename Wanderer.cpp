#include "include/Wanderer.h"

Wanderer::Wanderer()
{
	
}

Wanderer::~Wanderer()
{
	
}

void Wanderer::update(sf::Time t_deltatime, bool t_destroyWanderer)
{
	if (!t_destroyWanderer)
	{
		//m_originWanderCheck.setPosition(m_wandererPos);
		m_previousWanderPos = sf::Vector2f((m_wandererAim.x - m_wandererPos.x) / 100, (m_wandererAim.y - m_wandererPos.y) / 100);
		m_wandererPos.x += (m_wandererAim.x - m_wandererPos.x) / 200;
		m_wandererPos.y += (m_wandererAim.y - m_wandererPos.y) / 200;
		
		m_wandererSprite.setPosition(m_wandererPos);
		rotateToDirection();
		if ((m_wandererPos.x - m_wandererAim.x <= 5 && m_wandererPos.x - m_wandererAim.x >= -5) &&
			(m_wandererPos.y - m_wandererAim.y <= 5 && m_wandererPos.y - m_wandererAim.y >= -5))
		{
			generateNewPoint();
		}
	}
	else
	{
		int temp1 = rand() % 5;
		int temp2 = rand() % 6;
		int temp3 = rand() % 10;
		m_wandererPos = sf::Vector2f(screenHeight * (temp1+ 1) / (temp2+1), screenHeight / (temp3+1));
		generateNewPoint();
	}
}

void Wanderer::render(sf::RenderWindow& t_window, bool t_destroyWanderer)
{
	if (!t_destroyWanderer)
	{
		t_window.draw(m_wandererSprite);
		t_window.draw(m_originWanderCheck);
	}
	else
	{
		std::cout << "why???????" << std::endl;
	}
	
}

void Wanderer::generateNewPoint()
{
	if(hitWall)
	{ 
		m_wandererAim = sf::Vector2f(m_wandererPos.x + (rand() % 500)* -1, m_wandererPos.y + (rand() % 600) * -1);
		hitWall = false;
	}
	else
	{
		m_wandererAim = sf::Vector2f(m_wandererPos.x + rand() % 800, m_wandererPos.y + rand() % 600);
	}

}

void Wanderer::rotateToDirection()
{
	m_angleCalculator = m_wandererPos - m_wandererAim;//m_wandererAim - m_wandererPos;
	rotationValue = m_angleCalculator.y / m_angleCalculator.x;
	rotateSet = atan(rotationValue);
	m_wandererSprite.setRotation(rotationValue);
	currentRotation += rotateSet;
	if (currentRotation > 360)
	{
		currentRotation -= 360;
	}
	if (currentRotation < 0)
	{
		currentRotation += 360;
	}
}

void Wanderer::initWander(sf::RenderWindow& t_window)
{
	currentRotation = 0;
	m_wandererTexture.loadFromFile("ASSETS/IMAGES/craft.png");
	screenWidth = t_window.getSize().x;
	screenHeight = t_window.getSize().y;
	m_wandererPos = sf::Vector2f((screenWidth  /2 ),  (screenHeight / 5));
	m_wandererSprite.setTexture(m_wandererTexture);
	m_wandererSprite.setOrigin( m_wandererSprite.getGlobalBounds().width / 2, m_wandererSprite.getGlobalBounds().height / 2);
	generateNewPoint();
	
	/*m_originWanderCheck.setRadius(2.f);
	m_originWanderCheck.setPosition(m_wandererPos);
	m_originWanderCheck.setFillColor(sf::Color::Magenta);*/
}



sf::Vector2f Wanderer::getPosition()
{
	return m_wandererPos;
}

sf::Sprite Wanderer::getWanderer()
{
	return m_wandererSprite;
}

void Wanderer::bounce()
{
	m_wandererPos -= sf::Vector2f((m_previousWanderPos.x * 2), (m_previousWanderPos.y * 2));
	hitWall = true;
	generateNewPoint();
	//m_wandererAim = sf::Vector2f(-m_previousWanderPos.x , -m_previousWanderPos.y );
}
