#pragma once
#include <vector>

class map
{
private:
	std::vector < std::vector<int> > _mapPosition;
	int _size;
public:
	map();
	map(int size);
	~map();

	void initializeMap(int size);
};

