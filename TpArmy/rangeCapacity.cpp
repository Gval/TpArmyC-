#include "stdafx.h"
#include "rangeCapacity.h"


rangeCapacity::rangeCapacity()
{
}

rangeCapacity::rangeCapacity(int level) : capacity(level)
{
}

rangeCapacity::~rangeCapacity()
{
}

void rangeCapacity::updateValue() {
	setValue((10 + getLevel()) * 2);
}
