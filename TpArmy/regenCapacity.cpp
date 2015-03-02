#include "stdafx.h"
#include "regenCapacity.h"


regenCapacity::regenCapacity()
{
	updateValue();
}

regenCapacity::regenCapacity(int level) : capacity(level) 
{
	for (int i = 0; i < level; ++i)
	{
		upgrade();
	}
	updateValue();
}

regenCapacity::~regenCapacity()
{
}

void regenCapacity::updateValue() {
	setValue(getLevel()/100.0f);
}

void regenCapacity::upgrade()
{
	capacity::upgrade();
	updateValue();
}

std::ostream& operator<<(std::ostream &o, regenCapacity &r)
{
	return o << r.getLevel();
}