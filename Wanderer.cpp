#include "include/Wanderer.h"

Wanderer::Wanderer()
{
	
}

Wanderer::~Wanderer()
{
}

void Wanderer::update(sf::Time t_deltatime)
{
	//m_originWanderCheck.setPosition(m_wandererPos);
	m_wandererPos.x += (m_wandererAim.x - m_wandererPos.x) / 100;
	m_wandererPos.y += (m_wandererAim.y - m_wandererPos.y) / 100;
	m_wandererSprite.setPosition(m_wandererPos);
	rotateToDirection();
	if ((m_wandererPos.x - m_wandererAim.x <= 5 && m_wandererPos.x - m_wandererAim.x >= -5) &&
		(m_wandererPos.y - m_wandererAim.y <= 5 && m_wandererPos.y - m_wandererAim.y >= -5))
	{
		//if (currentRotation <= m_wandererSprite.getRotation() + 5 && currentRotation >= m_wandererSprite.getRotation() - 5)
		//{

			generateNewPoint();
		//}
	}
}

void Wanderer::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_wandererSprite);
	t_window.draw(m_originWanderCheck);
}

void Wanderer::generateNewPoint()
{
	m_wandererAim = sf::Vector2f(rand() % 800, rand() % 600);

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
	m_wandererPos = sf::Vector2f( -1 * (screenWidth / 3), -1 * (screenHeight / 3));
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
