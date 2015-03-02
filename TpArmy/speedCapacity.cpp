#include "stdafx.h"
#include "speedCapacity.h"


speedCapacity::speedCapacity()
{
	updateValue();
}

speedCapacity::speedCapacity(int level) : capacity(level) {
	for (int i = 0; i < level; ++i)
	{
		upgrade();
	}
	updateValue();
}


speedCapacity::~speedCapacity()
{
}

void speedCapacity::updateValue() {
	setValue(1.0f + getLevel());
}

void speedCapacity::upgrade()
{
	capacity::upgrade();
	updateValue();
}

std::ostream& operator<<(std::ostream &o, speedCapacity &r)
{
	return o << r.getLevel();
}