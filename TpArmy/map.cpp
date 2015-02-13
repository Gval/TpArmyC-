#include "stdafx.h"
#include "map.h"


map::map()
{
}

map::map(int size) : _size(size)
{
	initializeMap(size);
}

map::~map()
{
}

void map::initializeMap(int size)
{
	for (int i = 0; i < size; ++i)
	{
		std::vector<int> row;
		
		for (int j = 0; j < size; ++j)
		{
			row.push_back(0);
		}
		_mapPosition.push_back(row);
	}
}
