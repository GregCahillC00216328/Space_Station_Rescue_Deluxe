#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
class Player
{
public:
	Player();
	~Player();
	void update(double dt);
	void render(sf::RenderWindow& window);
	void movement(sf::Vector2f const& pos);
	void resetSpeed();
	void increaseSpeed();
	void decreaseSpeed();

	void increaseRotation();
	void decreaseRotation();

	void handleKeyInput();
	
	sf::Vector2f getPosition() const;

	void takeDamge();
	int getHealth();
	void heal();
	sf::RectangleShape getPlayer() const;
private:
	void adjustRotation();
	sf::RectangleShape m_player;

	double m_speed=0;
	double const MAX_SPEED = 400;
	double m_rotation = 0;
	double const DEG_TO_RAD = 3.141592 / 180.0f;

	bool m_enableRotation = true;
	sf::Vector2f m_previousPosition;
	int m_previousSpeed;
	double m_previousRotation{ 0.0 };
	int health = 10;
};

