#include "stdafx.h"
#include "health.h"


health::health()
{
}

health::health(int level) : capacity(level) {

}

health::~health()
{
}


void health::updateValue() {
	setMaxValue(1.0f + getLevel() * 10);
}

float health::getMaxValue() {
	return _maxValue;
}
void health::setMaxValue(float value) {
	_maxValue = value;
}
