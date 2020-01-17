#include "include/Player.h"
#include <iostream>



Player::Player()
{
	
}
Player::~Player()
{
}
void Player::update(double t_deltaTime)
{
	m_previousPosition = m_player.getPosition();
	movement(sf::Vector2f(m_player.getPosition().x + cos(m_rotation * DEG_TO_RAD) * m_speed * (t_deltaTime / 1000),
		m_player.getPosition().y + sin(m_rotation * DEG_TO_RAD) * m_speed * (t_deltaTime / 1000)));
	m_player.setRotation(m_rotation);

	handleKeyInput();
	
	m_enableRotation = true;

}

void Player::render(sf::RenderWindow& t_window)
{
	t_window.draw(m_player);
}

void Player::movement(sf::Vector2f const& t_pos)
{
	m_player.setSize(sf::Vector2f(40,40));
	m_player.setOrigin(m_player.getSize().x / 2.0, m_player.getSize().y / 2.0);
	m_player.setPosition(t_pos);
}

void Player::resetSpeed()
{
	m_speed = 0;
	health = 10;
}

void Player::handleKeyInput()
{
	if (m_enableRotation)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_previousRotation = m_rotation;
			increaseRotation();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_previousRotation = m_rotation;
			decreaseRotation();
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_previousSpeed = m_speed; 
		increaseSpeed();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_previousSpeed = m_speed;
		decreaseSpeed();
	}

}
/// <summary>
/// @brief Increases the speed by 1, max speed is capped at 100. 
/// </summary>
void Player::increaseSpeed()
{
	if (m_speed < MAX_SPEED)
	{
		m_speed += 2;
	}
}

/// <summary>
/// @brief Decreases the speed by 1, min speed is capped at -100.
/// </summary>
void Player::decreaseSpeed()
{
	if (m_speed > -MAX_SPEED)
	{
		m_speed -= 2;
	}
}

void Player::deflect()
{
	{
		if (m_speed != 0)
		{
			m_enableRotation = false;
			m_player.setPosition(m_previousPosition);
			// Apply small force in opposite direction of travel.
			if (m_previousSpeed < 0)
			{
				m_speed = 30;
			}
			else
			{
				m_speed = -30;

			}
		}
	}
}

/// <summary>
/// @brief Increases the rotation by 1 degree, wraps to 0 degrees after 359.
/// </summary>
void Player::increaseRotation()
{
	m_rotation += 2;
	if (m_rotation >= 360.0)
	{
		m_rotation = 0;
	}
}

/// <summary>
/// @brief Decreases the rotation by 1 degree, wraps to 359 degrees after 0.
/// </summary>
void Player::decreaseRotation()
{
	m_rotation -= 2;
	if (m_rotation <= 0.0)
	{
		m_rotation = 358;
	}
}


sf::Vector2f Player::getPosition() const
{
	return m_player.getPosition();
}

sf::RectangleShape Player::getPlayer() const
{
	return m_player;
}


void Player::takeDamge()
{
	health -= 1;
}

int Player::getHealth()
{
	return health;
}

void Player::heal()
{
	health += 3;
	if (health > 10)
	{
		health = 10;
	}
}

void Player::adjustRotation()
{
	if (m_rotation != m_previousRotation)
	{
		if (m_rotation > m_previousRotation)
		{
			m_rotation = m_previousRotation - 1;
		}
		else
		{
			m_rotation = m_previousRotation + 1;
		}
	}
}