#include "stdafx.h"
#include "health.h"


health::health()
{
	updateValue();
	setValue(_maxValue);
}

health::health(int level) : capacity(level) {
	updateValue();
	setValue(_maxValue);
}

health::~health()
{
}

void health::upgrade(){
	capacity::upgrade();
	updateValue();
	setValue(_maxValue);
}

void health::updateValue() {
	setMaxValue((1.0f + getLevel()) * 10);
}

float health::getValue() const{
	return _Value;
}
void health::setValue(float value) {
	if (value > _maxValue)
	{
		value = _maxValue;
	}

	_Value = value;
	int i = 0;
}

float health::getMaxValue() const{
	return _maxValue;
}
void health::setMaxValue(float value) {
	_maxValue = value;
}

std::ostream& operator<<(std::ostream &o, health &r)
{
	return o << r.getLevel();
}