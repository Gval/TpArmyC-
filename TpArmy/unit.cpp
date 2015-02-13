#include "stdafx.h"
#include "unit.h"
#include <random>


unit::unit()
{
	intializeUnit();
}

unit::unit(int level) : _unitLevel(level)
{
	intializeUnit();
}

unit::unit(std::string iaCode, std::vector<int> levelsCapacity) : _iaCode(iaCode)
{
	for (int i = 0; i < _listCapacity.size(); ++i)
	{
		for (int j = 0; j < levelsCapacity[i]; ++j)
		{
			_listCapacity[i]->upgrade();
		}
	}
}

unit::~unit()
{
}

int unit::getId()
{
	return _Id;
}

capacity& unit::getCapacity(int index)
{
	if (index < _listCapacity.size())
	{
		return *_listCapacity[index];
	}
	
}
speedCapacity& unit::getSpeed()
{
	speedCapacity& s1 = dynamic_cast<speedCapacity& >(*_listCapacity[0]);
	return s1;
}
health& unit::getHealth()
{
	health& s1 = dynamic_cast<health& >(*_listCapacity[1]);
	return s1;
}

armorCapacity& unit::getArmor()
{
	armorCapacity& s1 = dynamic_cast<armorCapacity& >(*_listCapacity[2]);
	return s1;
}

rangeCapacity& unit::getRange()
{
	rangeCapacity& s1 = dynamic_cast<rangeCapacity& >(*_listCapacity[5]);
	return s1;
}

damageCapacity& unit::getDamage()
{
	damageCapacity& s1 = dynamic_cast<damageCapacity& >(*_listCapacity[4]);
	return s1;
}

regenCapacity& unit::getRegen()
{
	regenCapacity& s1 = dynamic_cast<regenCapacity& >(*_listCapacity[3]);
	return s1;
}

reloadSpeedCapacity& unit::getReload()
{
	reloadSpeedCapacity& s1 = dynamic_cast<reloadSpeedCapacity& >(*_listCapacity[6]);
	return s1;
}

int unit::getunitLevel()
{
	return _unitLevel;
}

point& unit::getPosition()
{
	return _unitPosition;
}

void unit::refresh()
{
	int max = getHealth().getMaxValue();
	int now = getHealth().getValue();

	now += getRegen().getValue();
	if (now > max)
	{
		now = max;
	}

	getHealth().setValue(now);
}

bool unit::isAlive()
{
	if (getHealth().getValue() <= 0)
	{
		return false;
	}

	return true;
}

bool unit::shoot()
{
	if (_reloadTime > 0) {
		return false;
	}
	else {
		return true;
	}
}

void unit::takeDamage(float value)
{
	int totaldamage = value - getArmor().getValue();

	if (totaldamage > 0)
	{
		getHealth().setValue(getHealth().getValue() - totaldamage);
	}
}


void unit::giveLevelToCapacity()
{
	int givenLevels = 0;
	int random = 0;

	while (givenLevels < _unitLevel)
	{
		random = rand() % 7;
		getCapacity(random);
		givenLevels++;
	}
}

void unit::intializeUnit() {
	//initialiser
	_listCapacity.emplace_back(new health());
	_listCapacity.emplace_back(new armorCapacity());
	_listCapacity.emplace_back(new speedCapacity());
	_listCapacity.emplace_back(new health());
	_listCapacity.emplace_back(new armorCapacity());
	_listCapacity.emplace_back(new reloadSpeedCapacity());
	_listCapacity.emplace_back(new damageCapacity());
	_listCapacity.emplace_back(new rangeCapacity());
}