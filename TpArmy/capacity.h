#pragma once
#include <ostream>

class capacity
{
public:
	capacity();
	capacity(int level);
	~capacity();

	virtual void upgrade();
	void downgrade();
	virtual void updateValue();
	int getLevel();
	virtual float getValue();
	virtual void setValue(float setVal);

	
private:
	int _Level;
	float _value;
};

std::ostream& operator <<(std::ostream&, capacity&);
