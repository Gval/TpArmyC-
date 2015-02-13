#pragma once
#include "capacity.h"
class reloadSpeedCapacity :
	public capacity
{
public:
	reloadSpeedCapacity();
	reloadSpeedCapacity(int level);
	~reloadSpeedCapacity();

	void updateValue();
};

