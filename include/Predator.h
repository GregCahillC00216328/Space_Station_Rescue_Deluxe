#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <queue>
#include "Player.h"


class Predator
{
public:
	Predator();
	~Predator();
	Predator(sf::Texture const& texture);

	void update(sf::Vector2f t_playerPos, double dt);
	void render(sf::RenderWindow& window);
	void init(sf::Vector2f position);
	sf::Sprite getSprites();
	void takeDamge();
private:
	void initSprites();

	void updateMovement(double dt);
	sf::Vector2f unitVectorify(sf::Vector2f t_temp);
	sf::Vector2f seek(sf::Vector2f playerPosition);

	double m_rotation{ 0.0 };

	sf::Vector2f m_velocity{0.0,0.0};
	sf::Vector2f m_steering;
	sf::Vector2f m_predPos;
	sf::Texture predTexture;
	sf::Sprite pred;
	float MAX_SPEED = 50.0f;

	enum class AiBehaviour
	{
		SEEK_PLAYER,
		WANDER
	} 
	m_aiBehaviour;

	int m_health = 10;
	double const DEG_TO_RAD = 3.141592 / 180.0f;
};

