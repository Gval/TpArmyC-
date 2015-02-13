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
};

