#ifndef WANDERER
#define WANDERER
#include <iostream>
#include <SFML/Graphics.hpp>
class Wanderer
{
private:
	sf::Texture m_wandererTexture;// texture for wander ship
	sf::Sprite m_wandererSprite;	// sprite for wander ship
	sf::Vector2f m_wandererPos;	// sets the wanderer position
	std::vector<Wanderer> m_wandererArray;	// stores all of the wanderers in a dynamic array
	sf::Vector2f m_wandererAim;	// genreal area the wanderer wants to move to
	sf::Vector2f m_angleCalculator;	//finds the angle for the wanderer to face based on direction
	float rotationValue;	// stores the rotation for the direction of the wanderer
	float rotateSet;	// calculate the rotation in degrees and stores the result here
	float currentRotation;	// stores current wanderer rotation
	float screenWidth;	// used to store width of screen
	float screenHeight;	// used to store height of screen
	sf::CircleShape m_originWanderCheck;	// used for testing purposes only
	sf::Vector2f m_previousWanderPos;
	bool hitWall = false;
public:
	Wanderer();	//default constructor
	~Wanderer();	//destructor
	void update(sf::Time t_deltatime, bool t_destroyWanderer);	// update for the wander class
	void render(sf::RenderWindow& t_window, bool t_destroyWanderer);	// render window for the wander class
	void generateNewPoint();	// creates a new point for the ship to wander to
	void rotateToDirection();	// points wanderer in direction of movement
	void initWander(sf::RenderWindow &t_window);	// used to initialise the wanderer
	sf::Vector2f getPosition();
	sf::Sprite getWanderer();
	void bounce();
};
#endif // WANDERER

