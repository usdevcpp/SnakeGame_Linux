#include "GameMap.h"

void GameMap::Map()
{
	for (int i{ 0 };i < m_y;++i)
	{
		std::vector<char> temp; //for pushing back to the main vector
		for (int j{ 0 }; j < m_x;++j)
		{
			if (j == (m_x - 1))
			{
				temp.push_back('\n');
				continue;
			}
			temp.push_back(m_mapChar);
		}
		m_gameMap.push_back(temp);
	}
}

Vec2D<char>* GameMap::GetMap()
{
	Vec2D<char>* p{ &m_gameMap };
	return p;
}

char GameMap::GetMapChar()
{
	return m_mapChar;
}

int GameMap::GetMapSizeX()
{
	return m_x;
}

int GameMap::GetMapSizeY()
{
	return m_y;
}

void GameMap::SnakeMap()
{
	auto* p{ &m_gameMap };
	for (int i{ m_y_BorderLeft + 1 };i < m_y_BorderRight - 1;++i)
	{
		std::vector<char> temp; //for pushing back to the main vector
		for (int j{ m_x_BorderUpper + 1 }; j < m_x_BorderLower - 1;++j)
		{
			m_gameMap[i][j] = ' ';
		}
		//m_gameMap.push_back(temp);
	}
}

int GameMap::GetMemX() const
{
	return m_memX;
}

int GameMap::GetMemY() const
{
	return m_memY;
}

void GameMap::SetMemX(int n)
{
	if (GameMap::BorderCollision(GameMap::GetMemX(), GameMap::GetMemY()))
	{
		m_memX = m_memX;
	}
	else
	{
		m_memX += n;
	}
}

void GameMap::SetMemY(int n)
{
	if (GameMap::BorderCollision(GameMap::GetMemX(), GameMap::GetMemY()))
	{
		m_memY = m_memY;
	}
	else
	{
		m_memY += n;
	}
	
}

void GameMap::SetCharInMap(int x, int y, char r)
{
	m_gameMap[y][x] = r;
}

void GameMap::SetCharInMapY(int y, char r)
{
	if(!(GameMap::BorderCollision(GameMap::GetMemX(), y)))
		m_gameMap[y][GameMap::GetMemX()] = r;
}

void GameMap::SetCharInMapX(int x, char r)
{
	if (!(GameMap::BorderCollision(x, GameMap::GetMemY())))
		m_gameMap[GameMap::GetMemY()][x] = r;
}

char GameMap::GetCurrentChar()
{
	return m_gameMap[GameMap::GetMemY()][GameMap::GetMemX()];
}

char GameMap::GetCurrentChar_Upper()
{
	if (GameMap::BorderCollision(GameMap::GetMemX(), GameMap::GetMemY()))
	{
		return ' ';
	}
	else
	{
		return m_gameMap[GameMap::GetMemY() - 1][GameMap::GetMemX()];
	}
}

char GameMap::GetCurrentChar_Lower()
{
	if (GameMap::BorderCollision(GameMap::GetMemX(), GameMap::GetMemY()))
	{
		return ' ';
	}
	else
	{
		return m_gameMap[GameMap::GetMemY() + 1][GameMap::GetMemX()];
	}
}

char GameMap::GetCurrentChar_Right()
{
	if (GameMap::BorderCollision(GameMap::GetMemX(), GameMap::GetMemY()))
	{
		return ' ';
	}
	else
	{
		return m_gameMap[GameMap::GetMemY()][GameMap::GetMemX() + 1];
	}
}

char GameMap::GetCurrentChar_Left()
{
	if (GameMap::BorderCollision(GameMap::GetMemX(), GameMap::GetMemY()))
	{
		return ' ';
	}
	else
	{
		return m_gameMap[GameMap::GetMemY()][GameMap::GetMemX() - 1];
	}
}

const int GameMap::GetBorderUpper()
{
	return m_x_BorderUpper;
}

const int GameMap::GetBorderLower()
{
	return m_x_BorderLower;
}

const int GameMap::GetBorderLeft()
{
	return m_y_BorderLeft;
}

const int GameMap::GetBorderRight()
{
	return m_y_BorderRight;
}

void GameMap::SetCharMiddle(char c)
{
	GameMap::SetCharInMap((m_x / 2), (m_y / 2), c);
}

bool GameMap::BorderCollision(int x, int y)
{
	if (x == m_x_BorderUpper || x == m_x_BorderLower - 1 || y == m_y_BorderLeft || y == m_y_BorderRight - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GameMap::CheckIfEmpty(int x, int y)
{
	if (m_gameMap[y][x] == ' ')
	{
		return true;
	}
	else
	{
		return false;
	}
}

void GameMap::PrintMap()
{

	for (std::vector<char> i : m_gameMap)
	{
		for (char j : i)
		{
			addch(' ');
			addch(j);
			
		}
	}

	move(0,0);
	//std::cout << "press arrow key or WASD to move" << "\n"; 
	//std::cout << "press 't' to remove the telemetry data" << "\n";
	//std::cout << "press 'p' to pause the game" << "\n";
	//std::cout << "press 'r' to restart the game" << "\n";
	//std::cout << "press 'q' to quit the game" << "\n";
	
	
	//m_cur.CursorVisibility(false); //false to hide the cursor
	//m_cur.SetCursorToStart();
}
