#include "include\Seeker.h"

Seeker::Seeker()
{
	
}

Seeker::~Seeker()
{
}

void Seeker::update(sf::Time t_deltaTime)
{
	//m_originSeekerCheck.setPosition(m_seekerPos + sf::Vector2f(5, 5));
	//m_seekerDetectCircle.setPosition(m_seekerPos.x + m_seekerDetectCircle.getGlobalBounds().width / 2, m_seekerPos.y + m_seekerSprite.getGlobalBounds().height / 2);
	//m_seekerDetectCircle.setPosition(m_seekerCirclePos.x + m_seekerDetectCircle.getRadius(), m_seekerCirclePos.y + m_seekerDetectCircle.getRadius());
	if (!chasingWorker)
	{
		m_seekerPos.x += (m_seekerAim.x - m_seekerPos.x) / 100;
		m_seekerPos.y += (m_seekerAim.y - m_seekerPos.y) / 100;
		m_seekerSprite.setPosition(m_seekerPos);
	}
	if ((m_seekerPos.x - m_seekerAim.x <= 5 && m_seekerPos.x - m_seekerAim.x >= -5) &&
		(m_seekerPos.y - m_seekerAim.y <= 5 && m_seekerPos.y - m_seekerAim.y >= -5))
	{
		generateNewPoint();
	}
	m_seekerCirclePos.x = ( m_seekerPos.x );
	m_seekerCirclePos.y = ( m_seekerPos.y);
	m_seekerDetectCircle.setPosition(m_seekerCirclePos.x - m_seekerDetectCircle.getRadius()  , m_seekerCirclePos.y - m_seekerDetectCircle.getRadius()  );
}

void Seeker::render(sf::RenderWindow& t_window)
{

	t_window.draw(m_seekerDetectCircle);
	t_window.draw(m_seekerSprite);
	t_window.draw(m_originSeekerCheck);
}

void Seeker::initSeeker(sf::RenderWindow& t_window)
{
	foundWanderer = false;
	screenWidth = t_window.getSize().x;
	screenHeight = t_window.getSize().y;
	m_seekerPos = sf::Vector2f(-1 * (screenWidth / 3) , -1 * (screenHeight / 3));
	m_seekerTexture.loadFromFile("ASSETS/IMAGES/seeker.png");
	m_seekerSprite.setTexture(m_seekerTexture);
	m_seekerSprite.setOrigin( m_seekerSprite.getGlobalBounds().width / 2,  m_seekerSprite.getGlobalBounds().height / 2);
	m_seekerDetectCircle.setOrigin(m_seekerDetectCircle.getGlobalBounds().width / 2 , m_seekerDetectCircle.getGlobalBounds().height / 2);
	m_seekerCirclePos = sf::Vector2f(-1 * (m_seekerSprite.getOrigin().x), -1 * (m_seekerSprite.getOrigin().y));

	m_seekerDetectCircle.setRadius(m_seekerSprite.getGlobalBounds().width * 3);
	m_seekerDetectCircle.setPosition(m_seekerPos.x - m_seekerDetectCircle.getRadius() /2, m_seekerPos.y - m_seekerDetectCircle.getRadius() / 2);
	m_seekerDetectCircle.setFillColor(sf::Color::Red);

	//m_originSeekerCheck.setRadius(2.f);
	//m_originSeekerCheck.setPosition(m_seekerPos + sf::Vector2f(5,5));
	//m_originSeekerCheck.setFillColor(sf::Color::Yellow);
}

void Seeker::generateNewPoint()
{
	m_seekerAim = sf::Vector2f(rand() %  static_cast<int>(screenWidth) , rand() % static_cast<int>(screenHeight));	// hard coded for testing purposes
}

void Seeker::withinWorkerDistance(Wanderer& t_wanderer)
{
	if (sqrt(pow(m_seekerDetectCircle.getPosition().x - t_wanderer.getPosition().x, 2) + pow(m_seekerDetectCircle.getPosition().y - t_wanderer.getPosition().y,2 ))
		<= m_seekerDetectCircle.getRadius())
	{
		chasingWorker = true;
		m_seekerPos.x = t_wanderer.getPosition().x - m_seekerPos.x / (pow(m_seekerDetectCircle.getPosition().x - t_wanderer.getPosition().x, 2) + pow(m_seekerDetectCircle.getPosition().y - t_wanderer.getPosition().y, 2) * 10);
		m_seekerPos.y = t_wanderer.getPosition().y - m_seekerPos.y / (pow(m_seekerDetectCircle.getPosition().x - t_wanderer.getPosition().x, 2) + pow(m_seekerDetectCircle.getPosition().y - t_wanderer.getPosition().y, 2) * 10);
		m_seekerSprite.setPosition(m_seekerPos);
		if (sqrt(pow(m_seekerDetectCircle.getPosition().x - t_wanderer.getPosition().x, 2) + pow(m_seekerDetectCircle.getPosition().y - t_wanderer.getPosition().y, 2))
			<= m_seekerDetectCircle.getRadius() / 2)
		{
		std::cout << "catching worker" << std::endl;
		chasingWorker = false;
		}
	}
}
