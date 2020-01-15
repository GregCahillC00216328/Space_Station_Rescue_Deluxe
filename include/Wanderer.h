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
public:
	Wanderer();	//default constructor
	~Wanderer();	//destructor
	void update(sf::Time t_deltatime);	// update for the wander class
	void render(sf::RenderWindow& t_window);	// render window for the wander class
	void generateNewPoint();	// creates a new point for the ship to wander to
	void rotateToDirection();	// points wanderer in direction of movement
};
#endif // WANDERER

