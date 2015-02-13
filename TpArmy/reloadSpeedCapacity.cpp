#include "stdafx.h"
#include "reloadSpeedCapacity.h"


reloadSpeedCapacity::reloadSpeedCapacity()
{
}

reloadSpeedCapacity::reloadSpeedCapacity(int level) : capacity(level)
{
}


reloadSpeedCapacity::~reloadSpeedCapacity()
{
}

void reloadSpeedCapacity::updateValue()
{
	setValue(1000 / getLevel());
}
