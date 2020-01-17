#pragma once
#include "MapTIle.h"
#include  "MapHolder.h"
class Map
{
public:
	Map();
	~Map();
	mapTile tile[40][22];
	MapHolder m_mapHolder;
	void init();
	void render(sf::RenderWindow& window,int i, int j);
private:
	sf::Vector2f mapArr[40][22];
	

	
};



