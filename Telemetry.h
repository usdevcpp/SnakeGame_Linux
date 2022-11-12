#pragma once

#include "GameMap.h"
#include "Snake.h"

class Telemetry : GameMap
{
private:

public:

	void BaseTelemetry(GameMap& map, Snake& snake);
	
	template <typename T>
	friend void print_vec(const std::vector<T>& v);
};


inline void print_vec(const std::vector<int>* v)
{
	printw("[");
	for (int i{ 0 }; i < v->size(); ++i)
	{
		printw("%d", v->at(i));
		if (i != (v->size() - 1))
		{
			printw(",");
		}
	}
	printw("]");
}