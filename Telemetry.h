#pragma once
#include<iostream>

#include "GameMap.h"
#include "Snake.h"

class Telemetry : GameMap
{
private:

public:

	void BaseTelemetry(GameMap& map, Snake& snake);
	
	template <typename T>
	friend std::ostream& operator<<(std::ostream& os, const std::vector<T>& v);
};


inline std::ostream& operator<<(std::ostream& os, const std::vector<int>& v)
{
	os << "[";
	for (int i{ 0 }; i < v.size(); ++i)
	{
		os << v[i];
		if (i != (v.size() - 1))
		{
			os << ',';
		}
	}
	os << "]";
	return os;
}