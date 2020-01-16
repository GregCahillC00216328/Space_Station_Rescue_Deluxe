#pragma once
#include <SFML/Graphics.hpp>
class mapTile
{
public:
	

	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f pos;
	void init() {
		if (!texture.loadFromFile("ASSETS/Map/block.png"))
		{
		}
		sprite.setTexture(texture);
	}
	void setPos(sf::Vector2f t_pos) { pos = t_pos; sprite.setPosition(pos); };
};



