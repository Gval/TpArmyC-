#include "stdafx.h"
#include "speedCapacity.h"


speedCapacity::speedCapacity()
{
}

speedCapacity::speedCapacity(int level) : capacity(level) {

}


speedCapacity::~speedCapacity()
{
}

void speedCapacity::updateValue() {
	setValue(1.0f + getLevel());
}

