#pragma once
#include "capacity.h"
class speedCapacity :
	public capacity
{
public:
	speedCapacity();
	speedCapacity(int level);
	~speedCapacity();

	void updateValue();
};

