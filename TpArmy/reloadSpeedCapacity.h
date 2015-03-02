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
	void upgrade();
};

std::ostream& operator<<(std::ostream &o, reloadSpeedCapacity &r);


