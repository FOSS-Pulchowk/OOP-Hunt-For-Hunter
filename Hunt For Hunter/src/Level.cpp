#include "Level.h"
#include <fstream>
#include <Common.h>
#include<iostream>
#include<ResourceManager.h>


Level::Level(const std::string &fileName)
{
	//resourceManager = resourceManager;
	std::ifstream file;
	file.open(fileName);

	
	if (file.fail()) {
		GameEngine::Error(4,"Failed to open " + fileName,"Unable to open file");
	}
	std::string temp;
	file >> temp >> _numhumans;
	while (std::getline(file, temp))
	{

     _leveldata.push_back(temp);
	}
	_spriteBatch.begin();
	glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);
	GameEngine::Color wcolor;
	wcolor.r = 255;
	wcolor.g = 255;
	wcolor.b = 255;
	wcolor.a = 255;

	
	for (int y = 0; y < _leveldata.size(); y++)
	{
		for (int x = 0; x < _leveldata[y].size(); x++)
		{
			char tile = _leveldata[y][x];
			

			
			glm::vec4 destRect(x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH);

			// Process the tile
			switch (tile) {
			
			case 'R':
				_spriteBatch.draw(destRect,
					uvRect,
					GameEngine::ResourceManager::getTexture("textures/red_bricks.png").id,
					0.0f,
					wcolor);
				break;
			case 'G':
				_spriteBatch.draw(destRect,
					uvRect,
					GameEngine::ResourceManager::getTexture("textures/red_bricks.png").id,
					0.0f,
					wcolor);
				break;
			case 'L':
				_spriteBatch.draw(destRect,
					uvRect,
					GameEngine::ResourceManager::getTexture("textures/red_bricks.png").id,
					0.0f,
					wcolor);
				break;
			case 'B':
				
				break;
			case '@':
				//_levelData[i][x] = '.';
				_startPlayerPos.x = x * TILE_WIDTH;
				_startPlayerPos.y = y * TILE_WIDTH;
				break;
			case 'Z':
				
				//_levelData[][x] = '.';
				_zombieStartPosition.emplace_back(x * TILE_WIDTH, y * TILE_WIDTH);
				break;
			case '.':
				break;
			default:
				std::printf("Unexpected symbol %c at (%d,%d)", tile, x, y);
				break;
			}
		}
	}

	_spriteBatch.end();


}


Level::~Level()
{
}

void Level::draw()
{
	_spriteBatch.renderBatch();

}
