#pragma once
#include "capacity.h"
class rangeCapacity :
	public capacity
{
public:
	rangeCapacity();
	rangeCapacity(int level);
	~rangeCapacity();

	void updateValue();
	void upgrade();
};

std::ostream& operator<<(std::ostream &o, rangeCapacity &r);
