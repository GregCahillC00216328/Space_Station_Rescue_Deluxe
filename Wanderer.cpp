#include "include/Wanderer.h"

Wanderer::Wanderer()
{
	currentRotation = 0;
	m_wandererTexture.loadFromFile("ASSETS/IMAGES/craft.png");
	m_wandererPos = sf::Vector2f(0.f, 0.f);
	m_wandererSprite.setTexture(m_wandererTexture);
	m_wandererSprite.setOrigin(m_wandererPos.x + m_wandererSprite.getGlobalBounds().width / 2, m_wandererPos.y + m_wandererSprite.getGlobalBounds().height / 2);
	generateNewPoint();
}

Wanderer::~Wanderer()
{
}

void Wanderer::update(sf::Time t_deltatime)
{
	m_wandererPos.x += (m_wandererAim.x - m_wandererPos.x) / 100;
	m_wandererPos.y += (m_wandererAim.y - m_wandererPos.y) / 100;
	m_wandererSprite.setPosition(m_wandererPos);
	rotateToDirection();
	if ((m_wandererPos.x - m_wandererAim.x <= 5 && m_wandererPos.x - m_wandererAim.x >= -5) &&
		(m_wandererPos.y - m_wandererAim.y <= 5 && m_wandererPos.y - m_wandererAim.y >= -5))
	{
		if (currentRotation <= m_wandererSprite.getRotation() + 5 && currentRotation >= m_wandererSprite.getRotation() - 5)
		{

			generateNewPoint();
		}
	}
}

void Wanderer::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_wandererSprite);
}

void Wanderer::generateNewPoint()
{
	m_wandererAim = sf::Vector2f(rand() % 800, rand() % 600);

}

void Wanderer::rotateToDirection()
{
	m_angleCalculator = m_wandererAim - m_wandererPos;
	rotationValue = m_angleCalculator.y / m_angleCalculator.x;
	rotateSet = atan(rotationValue);
	m_wandererSprite.rotate(rotateSet);
	currentRotation += rotateSet;
}
