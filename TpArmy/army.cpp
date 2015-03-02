#include "stdafx.h"
#include "army.h"

struct PointDistance
{
	point pt;
	float dist;
	float id;
};

 // will be filled in with squared distances

float CalculateDistance(const point& pt1, const point& pt2)
{
	float deltaX = pt1._x - pt2._x;
	float deltaY = pt1._y - pt2._y;
	return (deltaX * deltaX) + (deltaY * deltaY);
}

// should be changed to use an algorithm, but for clarity done as a loop here


bool DistanceLess(const PointDistance& lhs, const PointDistance& rhs)
{
	return lhs.dist < rhs.dist;
}

bool DistanceMore(const PointDistance& lhs, const PointDistance& rhs)
{
	return lhs.dist > rhs.dist;
}



army::army()
{
}


army::army(int unitNumber, int globalLevel)
{
	for (int i = 0; i < unitNumber; ++i)
	{
		_unitList.push_back(new unit(globalLevel,i));
	}
}

army::army(std::vector<unit*> unitList)
{
	std::vector<unit*> new_;
	for (int i = 0; i < unitList.size(); i++)
	{
		new_.push_back(new unit(unitList[i]));
	}
	_unitList = new_;
}


unit& army::getUnit(int id)
{

	return *_unitList[id];
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

void army::setUnitList(std::vector<unit*> unitList)
{
	_unitList = unitList;
}

unit& army::getNearestUnit(point& p) const
{
	int pos = 0;

	std::vector<PointDistance> squaredDistances;

	for (int i = 0; i < _unitList.size(); ++i)
	{
		PointDistance pd;
		pd.pt = _unitList[i]->getPosition();
		pd.id = _unitList[i]->getId();
		pd.dist = CalculateDistance(p, pd.pt);
		squaredDistances.push_back(pd);
	}

	std::sort(squaredDistances.begin(), squaredDistances.end(), DistanceLess);
	
	for (int i = 0; i < squaredDistances.size(); ++i)
	{
		if (_unitList[squaredDistances[i].id]->isAlive())
		{
			pos = i;
			break;
		}
			
	}
	
	return *_unitList[squaredDistances[pos].id];
}
unit& army::getFurtherUnit(point& p) const
{
	int pos = 0;

	std::vector<PointDistance> squaredDistances;

	for (int i = 0; i < _unitList.size(); ++i)
	{
		PointDistance pd;
		pd.pt = _unitList[i]->getPosition();
		pd.id = _unitList[i]->getId();
		pd.dist = CalculateDistance(p, pd.pt);
		squaredDistances.push_back(pd);
	}

	std::sort(squaredDistances.begin(), squaredDistances.end(), DistanceMore);

	for (int i = 0; i < squaredDistances.size(); ++i)
	{
		if (_unitList[squaredDistances[i].id]->isAlive())
		{
			pos = i;
			break;
		}
	}

	return *_unitList[squaredDistances[pos].id];
}
unit& army::getLowestUnit(int capa_index)
{
	int level = 100;
	int pos = 0;

	for (int i = 0; i < _unitList.size(); ++i)
	{
		if (i == 0 && _unitList[i]->isAlive())
		{
			level = _unitList[i]->getCapacity(capa_index).getLevel();
			pos = 0;
		}
		else {
			if ((level > _unitList[i]->getCapacity(capa_index).getLevel()) && _unitList[i]->isAlive())
			{
				level = _unitList[i]->getCapacity(capa_index).getLevel();
				pos = i;
			}
		}
	}

	return *_unitList[pos];

}
unit& army::getHiggestUnit(int capa_index)
{
	int level = 0;
	int pos = 0;

	for (int i = 0; i < _unitList.size(); ++i)
	{
		if (i == 0 && _unitList[i]->isAlive())
		{
			level = _unitList[i]->getCapacity(capa_index).getLevel();
			pos = 0;
		}
		else {
			if ((level < _unitList[i]->getCapacity(capa_index).getLevel()) && _unitList[i]->isAlive())
			{
				level = _unitList[i]->getCapacity(capa_index).getLevel();
				pos = i;
			}
		}
	}

	//std::cout << " Ayant la plus grande val : " << getUnit(pos) << std::endl;

	return *_unitList[pos];
}

army& army::mutate(){
	int random = 0;

	army* arm = new army(_unitList);

	for (int i = 0; i < 5; ++i)
	{
		random = rand() % _unitList.size();
		_unitList[i] = new unit(_unitList[i]->_unitLevel, i);
	}

	return *arm;
}
/*
army* army::operator*(const army &r)const  {
	army * arm = new army();
	arm->score = 0;
	for (int i = 0; i < _unitList.size(); ++i)
	{
		arm->getUnitList().push_back(r._unitList[i] * _unitList[i]);
	}

	return arm;
}*/