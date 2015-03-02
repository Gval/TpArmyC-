#include "stdafx.h"
#include "capacity.h"


capacity::capacity() : _Level(0)
{

}

capacity::capacity(int level) : _Level(level)
{
}

capacity::~capacity()
{
}

void capacity::upgrade(){
	_Level++;
}
void capacity::downgrade() {
	_Level--;
}

int capacity::getLevel() {
	return _Level;
}

float capacity::getValue() {
	return _value;
}
void capacity::setValue(float setVal) {
	_value = setVal;
}

void capacity::updateValue()
{
}

std::ostream& operator<<(std::ostream& o, capacity& r)
{
	return o;
}