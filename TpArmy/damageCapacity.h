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
	void upgrade();
};

std::ostream& operator<<(std::ostream &o, damageCapacity &r);