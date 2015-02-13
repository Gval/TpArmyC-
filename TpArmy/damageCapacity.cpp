#include "stdafx.h"
#include "damageCapacity.h"


damageCapacity::damageCapacity()
{
}

damageCapacity::damageCapacity(int level) : capacity(level)
{
}

damageCapacity::~damageCapacity()
{
}

void damageCapacity::updateValue() {
	setValue((1 + getLevel()) * 1.5f);
}