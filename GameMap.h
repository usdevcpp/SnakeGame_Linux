#pragma once
#include<vector>
//#include <iostream>

#include"TerminalConfig.h"

template <typename T>
using Vec2D = std::vector<std::vector<T>>;

class GameMap
{
private:

	//resolution of the map
	const int m_x{22 +1};
	const int m_y{22};

	//vars for borders
	const int m_x_BorderUpper{ 0 }; //0
	const int m_x_BorderLower{ m_x - 1 }; //22
	const int m_y_BorderLeft{ 0 }; //0
	const int m_y_BorderRight{ m_y }; //22

	//memory vars: memory position of x and y - Initialization = where to start on the map
	int m_memY{ m_x/2 }; //
	int m_memX{ m_y/2 };
	
	char m_mapChar{};

	//2d vector for the map
	Vec2D<char> m_gameMap;

	//control the curser
	TerminalConfig m_cur;
	//ConsoleConfig m_CLI;

	

public:
	GameMap(char mapChar)
		:m_mapChar{mapChar}
	{

	}
	GameMap() = default;
	GameMap(const GameMap&) = delete;
	GameMap& operator=(const GameMap&) = delete;

	//Initialize the map with a char
	void Map();
	void SnakeMap();

	Vec2D<char>* GetMap(); //get the game map
	
	char GetMapChar();

	int GetMapSizeX();
	int GetMapSizeY();

	//set a specific char in the map
	void SetCharInMap(int x, int y, char r);
	//set\get a specific char in the map with a specific direction
	int GetMemX() const;
	int GetMemY() const;
	void SetMemX(int n);
	void SetMemY(int n);
	void SetCharInMapY(int y, char r);
	void SetCharInMapX(int x, char r);

	//Get all around char from "head" pov
	char GetCurrentChar();
	char GetCurrentChar_Upper();
	char GetCurrentChar_Lower();
	char GetCurrentChar_Right();
	char GetCurrentChar_Left();

	//Get Borders
	const int GetBorderUpper();
	const int GetBorderLower();
	const int GetBorderLeft();
	const int GetBorderRight();

	//set a char in the middle of the map - starting point
	void SetCharMiddle(char c);
	
	bool BorderCollision(int x, int y);

	//check if a specific place is empty
	bool CheckIfEmpty(int x, int y);

	//print\-update the map (when inside a while_true loop)-
	void PrintMap();

};

