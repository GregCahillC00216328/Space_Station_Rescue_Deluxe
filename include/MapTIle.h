#pragma once
#include <SFML/Graphics.hpp>
class mapTile
{
public:
	

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Texture flTexture;
	sf::Sprite flSprite;
	sf::Vector2f pos;
	void init() {
		if (!texture.loadFromFile("ASSETS/Map/block.png"))
		{
		}
		sprite.setTexture(texture);
		if (!flTexture.loadFromFile("ASSETS/Map/floor.png"))
		{
		}
		flSprite.setTexture(flTexture);

	}
	void setPos(sf::Vector2f t_pos) { pos = t_pos; sprite.setPosition(pos); flSprite.setPosition(pos); };
};



