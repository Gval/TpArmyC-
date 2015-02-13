#include "stdafx.h"
#include "armorCapacity.h"


armorCapacity::armorCapacity()
{
}

armorCapacity::armorCapacity(int level) : capacity(level) {

}

armorCapacity::~armorCapacity()
{
}

void armorCapacity::updateValue() {
	setValue(getLevel() * 2);
}