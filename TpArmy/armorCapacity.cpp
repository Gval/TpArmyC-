#include "stdafx.h"
#include "armorCapacity.h"


armorCapacity::armorCapacity()
{
	updateValue();
}

armorCapacity::armorCapacity(int level) : capacity(level) {
	for (int i = 0; i < level; ++i)
	{
		upgrade();
	}
	updateValue();
}

armorCapacity::~armorCapacity()
{
}

void armorCapacity::upgrade()
{
	capacity::upgrade();
	updateValue();
}

void armorCapacity::updateValue() {
	setValue(getLevel() * 2.0f);
}

std::ostream& operator<<(std::ostream &o, armorCapacity &r)
{
	return o << r.getLevel();
}