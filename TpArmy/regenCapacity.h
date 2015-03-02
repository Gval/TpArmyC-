#pragma once
#include "capacity.h"
class regenCapacity :
	public capacity
{
public:
	regenCapacity();
	regenCapacity(int level);
	~regenCapacity();

	void updateValue();
	void upgrade();
};

std::ostream& operator<<(std::ostream &o, regenCapacity &r);
