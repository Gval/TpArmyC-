#include "stdafx.h"
#include "rangeCapacity.h"


rangeCapacity::rangeCapacity()
{
	updateValue();
}

rangeCapacity::rangeCapacity(int level) : capacity(level)
{
	for (int i = 0; i < level; ++i)
	{
		upgrade();
	}
	updateValue();
}

rangeCapacity::~rangeCapacity()
{
}

void rangeCapacity::updateValue() {
	setValue((10 + getLevel()) * 2.0f);
}

void rangeCapacity::upgrade()
{
	capacity::upgrade();
	updateValue();
}


std::ostream& operator<<(std::ostream &o, rangeCapacity &r)
{
	return o << r.getLevel();
}