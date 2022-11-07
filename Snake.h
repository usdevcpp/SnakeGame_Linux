#pragma once
#include <random>
#include <chrono>
#include <string>

#include "GameMap.h"

template <typename T>
using Vec = std::vector<T>;

class Snake : GameMap
{
private:
	Vec<char> m_snake;
	const char m_snake_look;
	const int m_initialSize;

	int m_posState{ 4 };//initialization to where the snake will point at the start

	std::vector<int> m_memXpos{};
	std::vector<int> m_memYpos{};

	char m_foodLook{ '@' };
	std::mt19937 m_mtX { static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
	std::mt19937 m_mtY { static_cast<unsigned int>(std::chrono::steady_clock::now().time_since_epoch().count()) };
	int m_foodX{};
	int m_foodY{};
	bool m_f_runOnce_GenerateFood{ 1 };

	bool m_borderCollision{ false };
	bool m_selfCollision{ false };

	//Messages
	const std::string m_msg_gameOver{ "Game Over" };
	const std::string m_msg_pressToStart{ "Press any key to start" };
	const std::string m_msg_score{ "your score is: " };

public:
	Snake(char snakeLook, int initialSize)
		:m_snake_look{ snakeLook }, m_initialSize{ initialSize }
	{

	}
	Snake(const Snake&) = delete;
	Snake& operator=(const Snake&) = delete;

	Vec<char>* GetSnake();
	
	//Initialize the size and look of snake
	void InitializeSnake();
	
	void SetSnakeOnMap(GameMap& map, Snake& snake); //GameMap& map, int x, int y, Snake& snake);

	char GetSnakeLook();

	std::vector<int>* GetMemXpos();
	std::vector<int>* GetMemYpos();

	void UpdateMemPos(GameMap& map, int mov_pos);

	void SetPosState(int posState);
	int GetPosState();

	void MoveSnake(GameMap& map, Snake& snake, int mov_pos);

	void CheckCollision(GameMap& map, Snake& snake, int mov_pos);

	void GenerateFood(GameMap& map, bool runAgain);
	bool SnakeEat(GameMap& map, int mov_pos);
	void SnakeGrowth(Snake& snake, GameMap& map, bool SnakeEat);

	int GetFoodX();
	int GetFoodY();

	bool borderCollision();
	bool selfCollision();
	void MSG_SetGameOver(GameMap& map);
	void MSG_SetPressToStart(GameMap& map);
	void MSG_RemovePressToStart(GameMap& map);
	void MSG_SetScore(GameMap& map, Snake& snake);
};

