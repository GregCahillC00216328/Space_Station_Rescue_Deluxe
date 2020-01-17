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
	void deflect();
	void increaseRotation();
	void decreaseRotation();

	void handleKeyInput();
	
	sf::Vector2f getPosition() const;
	bool m_fire = false;
	void takeDamge();
	int getHealth();
	void heal();
	sf::RectangleShape getPlayer() const;
	sf::RectangleShape getBullet() const;

	sf::Texture playerTexture;
	sf::Sprite playerSprite;
	
private:
	void adjustRotation();
	sf::RectangleShape m_player;
	
	void fireFun();
	sf::Vector2f fireDir;
	sf::RectangleShape m_bullet;
	double m_speed=0;
	double const MAX_SPEED = 400;
	double m_rotation = 0;
	double const DEG_TO_RAD = 3.141592 / 180.0f;
	double dt;
	double bulRot=0;
	bool m_enableRotation = true;
	sf::Vector2f m_previousPosition;
	int m_previousSpeed;
	double m_previousRotation{ 0.0 };
	int health = 10;
};

