#include "include/Predator.h"
Predator::Predator()
{
}
Predator::~Predator()
{
}
Predator::Predator(sf::Texture const& texture)
	: m_aiBehaviour(AiBehaviour::SEEK_PLAYER)
	, m_steering(0, 0)
{
	
	initSprites();
}


void Predator::update(sf::Vector2f t_playerPos, double dt)
{
	sf::Vector2f dir;
	dir.x = t_playerPos.x - pred.getPosition().x;
	dir.y = t_playerPos.x - pred.getPosition().x;

	float hyp = sqrt(dir.x * dir.x + dir.y * dir.y);
	dir.x /= hyp;
	dir.y /= hyp;

	pred.setPosition(sf::Vector2f(pred.getPosition().x + dir.x * 200*(dt*1000), pred.getPosition().y + dir.x * 200*(dt/1000)));
	
}


void Predator::render(sf::RenderWindow& window)
{
	window.draw(pred);
}

void Predator::init(sf::Vector2f position)
{
	m_aiBehaviour = AiBehaviour::SEEK_PLAYER;
	pred.setPosition(position);
	initSprites();
	m_health = 10;
	m_predPos = pred.getPosition();
}

sf::Vector2f Predator::seek(sf::Vector2f playerPosition)
{

	return playerPosition - pred.getPosition();
}

sf::Sprite Predator::getSprites()
{
	return pred;
}

void Predator::takeDamge()
{
	m_health -= 1;
}



void Predator::initSprites()
{
	if (!predTexture.loadFromFile("ASSETS/Map/enemey.png"))
	{
	}
	pred.setTexture(predTexture);
	pred.setOrigin(20 / 2.0, 20 / 2.0);
}


void Predator::updateMovement(double dt)
{
	std::cout << m_rotation << std::endl;
	double speed = 200;
	sf::Vector2f newPos = (sf::Vector2f(pred.getPosition().x + cos(m_rotation * DEG_TO_RAD) * speed * (dt / 1000),
		pred.getPosition().y + sin(m_rotation * DEG_TO_RAD) *speed * (dt / 1000)));
		pred.setPosition(newPos.x, newPos.y);
		pred.setRotation(m_rotation);
}

sf::Vector2f Predator::unitVectorify(sf::Vector2f t_temp)
{
	int vecMag = sqrt((t_temp.x * t_temp.x) + (t_temp.y * t_temp.y));
	return sf::Vector2f((t_temp.x / vecMag), (t_temp.y / vecMag));
}
