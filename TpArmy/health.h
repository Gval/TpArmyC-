#pragma once
#include "capacity.h"

class health :
	public capacity
{
private:
	float _maxValue;
public:
	health();
	health(int level);
	~health();

	void setMaxValue(float value);
	float getMaxValue();
	void updateValue();
};

