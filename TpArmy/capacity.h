#pragma once

class capacity
{
public:
	capacity();
	capacity(int level);
	~capacity();

	void upgrade();
	void downgrade();
	virtual void updateValue();
	int getLevel();
	float getValue();
	void setValue(float setVal);

private:
	int _Level;
	float _value;
};

