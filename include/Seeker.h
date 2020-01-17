#ifndef SEEKER
#define SEEKER
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Wanderer.h"

class Seeker
{
private:
	sf::Vector2f m_seekerPos;
	sf::Texture m_seekerTexture;
	sf::Sprite m_seekerSprite;
	sf::Vector2f m_seekerAim;
	bool foundWanderer;
	float screenWidth;
	float screenHeight;
	sf::CircleShape m_seekerDetectCircle;
	sf::Vector2f m_seekerCirclePos;
	bool chasingWorker = false;
	sf::CircleShape m_originSeekerCheck; // used for testing purposes only
public:
	Seeker();
	~Seeker();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void initSeeker(sf::RenderWindow& t_window);
	void generateNewPoint();
	void withinWorkerDistance(Wanderer & t_wanderer);
};
#endif // SEEKER
