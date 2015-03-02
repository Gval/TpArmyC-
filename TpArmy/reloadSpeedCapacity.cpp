#include "stdafx.h"
#include "reloadSpeedCapacity.h"


reloadSpeedCapacity::reloadSpeedCapacity()
{
	updateValue();
}

reloadSpeedCapacity::reloadSpeedCapacity(int level) : capacity(level)
{
	for (int i = 0; i < level; ++i)
	{
		upgrade();
	}
	updateValue();
}


reloadSpeedCapacity::~reloadSpeedCapacity()
{
}

void reloadSpeedCapacity::updateValue()
{
	setValue(1000 / (getLevel() + 1.0f ));
}

void reloadSpeedCapacity::upgrade()
{
	capacity::upgrade();
	updateValue();
}

std::ostream& operator<<(std::ostream &o, reloadSpeedCapacity &r)
{
	return o << r.getLevel();
}