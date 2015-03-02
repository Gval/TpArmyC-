#pragma once
#include "capacity.h"
#include <ostream>

class health :
	public capacity
{
private:
	float _maxValue;
	float _Value;
public:
	health();
	health(int level);
	~health();

	virtual void upgrade();
	void setValue(float value);
	float getValue() const;
	void setMaxValue(float value);
	float getMaxValue() const;
	virtual void updateValue();
};

std::ostream& operator<<(std::ostream&, health &);
