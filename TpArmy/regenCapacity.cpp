#include "stdafx.h"
#include "regenCapacity.h"


regenCapacity::regenCapacity()
{
}

regenCapacity::regenCapacity(int level) : capacity(level) 
{
}

regenCapacity::~regenCapacity()
{
}

void regenCapacity::updateValue() {
	setValue(getLevel() * 3);
}