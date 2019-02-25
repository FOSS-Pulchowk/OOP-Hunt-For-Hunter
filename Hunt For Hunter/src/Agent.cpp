#include "Agent.h"
#include"Level.h"
#include"ResourceManager.h"
#include<algorithm>
Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::CollideWithLevel(const std::vector<std::string>& levelData)
{

	std::vector<glm::vec2> collideTilePositions;
	
	checkTilePosition(levelData,
		collideTilePositions,
		_position.x,
		_position.y);

	checkTilePosition(levelData,
		collideTilePositions,
		_position.x+AGENT_WIDTH,
		_position.y);

	checkTilePosition(levelData,
		collideTilePositions,
		_position.x,
		_position.y+ AGENT_WIDTH);

	checkTilePosition(levelData,
		collideTilePositions,
		_position.x+ AGENT_WIDTH,
		_position.y+ AGENT_WIDTH);

	for (int i = 0; i < collideTilePositions.size(); i++)
	{
		collideWithTile(collideTilePositions[i]);
	}

}


void Agent::draw(GameEngine::SpriteBatch& _spriteBatch)
{

	static int textureID = GameEngine::ResourceManager::getTexture("textures/player.png").id;

	const glm::vec4 uvRect(0.0f, 0.0f, 1.0f, 1.0f);

	glm::vec4 destRect;
	destRect.x = _position.x;
	destRect.y = _position.y;
	destRect.z = AGENT_WIDTH;
	destRect.w = AGENT_WIDTH;
	_spriteBatch.draw(destRect, uvRect,textureID,0.0f,_color);
}

void Agent::checkTilePosition(const std::vector<std::string>& levelData,
								std::vector<glm::vec2>& collideTilePositions,
								float x,
								float y)
{
	glm::vec2 cornerPos = glm::vec2(floor(_position.x / (float)TILE_WIDTH),
		floor(_position.y / (float)TILE_WIDTH));

	if (levelData[cornerPos.y][cornerPos.x] != '.')
	{
		collideTilePositions.push_back(cornerPos+glm::vec2((float)TILE_WIDTH/2.0f));

	}
}


void Agent::collideWithTile(glm::vec2 tilePos)
{
	const float AGENT_RADIUS = (float)AGENT_WIDTH / 2.0f;
	const float TILE_RADIUS= (float)TILE_WIDTH / 2.0f;
	const float MIN_DISTANCE = AGENT_RADIUS + TILE_RADIUS;
	glm::vec2 centerPlayerPos = _position + glm::vec2(AGENT_RADIUS);
	glm::vec2 distVec = _position - tilePos;

	float xDepth = MIN_DISTANCE - abs(distVec.x);

	float yDepth = MIN_DISTANCE - abs(distVec.y);

	

	if (xDepth > 0 || yDepth > 0)
	{
		if (std::max(xDepth,0.0f) < std:: max(yDepth, 0.0f))
		{
			if (distVec.x < 0)
			{
				_position.x -= xDepth;
			}
			else
			{
				_position.x += xDepth;
			}
		}
		else
		{
			if (distVec.y < 0)
			{
				_position.y -= xDepth;
			}
			else
			{
				_position.y += xDepth;
			}

		}
	}

}
