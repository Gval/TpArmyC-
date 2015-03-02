#pragma once
#include "capacity.h"
class armorCapacity :
	public capacity
{
public:
	armorCapacity();
	armorCapacity(int level);
	~armorCapacity();

	void updateValue();
	void upgrade();
};

std::ostream& operator<<(std::ostream &o, armorCapacity &r);
