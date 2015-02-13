#include "stdafx.h"
#include "army.h"


army::army()
{
}


army::army(int unitNumber, int globalLevel)
{
	for (int i = 0; i < unitNumber; ++i)
	{
		_unitList.push_back(new unit(globalLevel));
	}
}

army::army(std::vector<unit*> unitList) : _unitList(unitList)
{

}


unit& army::getUnit(int id)
{
	for (int i = 0; i < _unitList.size(); ++i)
	{
		if (_unitList[i]->getId() == id)
		{
			return *_unitList[id];
		}
	}
}
	

void army::purge()
{
	for (int i = 0; i < _unitList.size(); ++i)
	{
		if (_unitList[i]->isAlive() == false)
		{
			_unitList[i]->~unit();
		}
	}
}

std::vector<unit*> army::getUnitList()
{
	return _unitList;
}

int army::size()
{
	return _unitList.size();
}

army::~army()
{
}
