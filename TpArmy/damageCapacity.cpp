#include "stdafx.h"
#include "damageCapacity.h"


damageCapacity::damageCapacity()
{
	updateValue();
}

damageCapacity::damageCapacity(int level) : capacity(level)
{
	for (int i = 0; i < level; ++i)
	{
		upgrade();
	}
	updateValue();
}

damageCapacity::~damageCapacity()
{
}

void damageCapacity::updateValue() {
	setValue((1 + getLevel()) * 1.5f);
}

void damageCapacity::upgrade()
{
	capacity::upgrade();
	updateValue();
}

std::ostream& operator<<(std::ostream &o, damageCapacity &r)
{
	return o << r.getLevel();
}