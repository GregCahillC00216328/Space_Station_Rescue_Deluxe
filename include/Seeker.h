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
	float caughtWorkersbySeeker;
	sf::Vector2f m_previousSeekerPos;
	bool hitWall = false;
public:
	Seeker();
	~Seeker();
	void update(sf::Time t_deltaTime);
	void render(sf::RenderWindow& t_window);
	void initSeeker(sf::RenderWindow& t_window);
	void generateNewPoint();
	bool withinWorkerDistance(Wanderer & t_wanderer, bool t_destroyWanderer);
	sf::Sprite getSeeker();
	void bounce();
};
#endif // SEEKER
