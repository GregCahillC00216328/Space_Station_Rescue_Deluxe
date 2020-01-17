/// <summary>
/// author Dylan Curran and Greg Cahill
/// January 2020
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Map.h"
#include "Wanderer.h"
#include "Predator.h"
#include "Seeker.h"
class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:
	Seeker m_seeker;
	Predator m_pred;
	Player m_pChar;
	Map world;
	Wanderer m_wanderer;
	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void forLoopLibrary();
	void setupFontAndText();
	void setupSprite();
	sf::View player_view;
	sf::View miniMap_view;
	sf::View default_view;
	sf::RenderWindow m_window; // main SFML window
	sf::RenderWindow m_minimap;
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	bool m_exitGame; // control exiting game
	bool destroyWanderer;	// bool to check if wanderer needs to be destroyed
	float caughtWanderer;	// counts how many wanderers the player caught

	sf::Texture mapTexture;
	sf::Sprite mapSprite;

	

};

#endif // !GAME_HPP

