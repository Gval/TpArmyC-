#pragma once
#include "capacity.h"
class damageCapacity :
	public capacity
{
public:
	damageCapacity();
	damageCapacity(int level);
	~damageCapacity();

	void updateValue();
};

