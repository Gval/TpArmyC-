#include "stdafx.h"
#include "unit.h"
#include <random>
#include <string>
#include <iostream>

unit::unit()
{
	intializeUnit();
}

unit::unit(int level, int i) : _unitLevel(level), _Id(i)
{
	intializeUnit();
	giveLevelToCapacity();
	giveIa();
}

unit::unit(std::string iaCode, std::vector<int> levelsCapacity) : _iaCode(iaCode)
{
	for (int i = 0; i < _listCapacity.size(); ++i)
	{
		for (int j = 0; j < levelsCapacity[i]; ++j)
		{
			_listCapacity[i]->upgrade();
			_unitLevel++;
		}
	}
}

unit::unit(const unit *u)
{
	intializeUnit();
	for (int i = 0; i < u->_listCapacity.size(); ++i)
	{
		for (int j = 0; j < u->_listCapacity[i]->getLevel(); ++j)
		{
			_listCapacity[i]->upgrade();
			_unitLevel++;
		}
	}

	_Id = u->_Id;
	_iaCode = u->_iaCode;
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
	speedCapacity& s1 = dynamic_cast<speedCapacity& >(*(_listCapacity[0]));
	return s1;
}
health& unit::getHealth()
{
	health& s1 = dynamic_cast<health&>(*(_listCapacity[1]));
	return s1;
}

armorCapacity& unit::getArmor()
{
	armorCapacity& s1 = dynamic_cast<armorCapacity& >(*(_listCapacity[2]));
	return s1;
}

rangeCapacity& unit::getRange()
{
	rangeCapacity& s1 = dynamic_cast<rangeCapacity& >(*(_listCapacity[5]));
	return s1;
}

damageCapacity& unit::getDamage()
{
	damageCapacity& s1 = dynamic_cast<damageCapacity& >(*(_listCapacity[4]));
	return s1;
}

regenCapacity& unit::getRegen()
{
	regenCapacity& s1 = dynamic_cast<regenCapacity& >(*(_listCapacity[3]));
	return s1;
}

reloadSpeedCapacity& unit::getReload()
{
	reloadSpeedCapacity& s1 = dynamic_cast<reloadSpeedCapacity& >(*(_listCapacity[6]));
	return s1;
}

int unit::getunitLevel()
{
	return _unitLevel;
}

point unit::getPosition()
{
	return _unitPosition;
}

void unit::refresh()
{
	float now = getHealth().getValue();

	now += getRegen().getValue();

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
	float totaldamage = value - getArmor().getValue();

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
		getCapacity(random).upgrade();
		givenLevels++;
	}
}

void unit::intializeUnit() {
	_listCapacity.emplace_back(new speedCapacity());
	_listCapacity.emplace_back(new health());
	_listCapacity.emplace_back(new armorCapacity());
	_listCapacity.emplace_back(new regenCapacity());
	_listCapacity.emplace_back(new damageCapacity());
	_listCapacity.emplace_back(new rangeCapacity());
	_listCapacity.emplace_back(new reloadSpeedCapacity());
}

void unit::setPosition(const point& p)
{
	this->_unitPosition = point(p._x, p._y);
}

std::ostream& operator<<(std::ostream &o, unit &r)
{
	return o << r.getHealth() << " " << r.getArmor() << " " << r.getDamage() << " " << r.getRange() << " " << r.getRegen() << " " << r.getReload() << " " << r.getSpeed() << " " << r.getIa();
}

void unit::giveIa()
{
	int random = 0;

	random = rand() % 2;
	if (random == 0)
	{
		_iaCode = "L";
	}
	else {
		_iaCode = "H";
	}

	random = rand() % 8;
	if (random == 7)
	{
		_iaCode = _iaCode + "D";
	}
	else {
		_iaCode = _iaCode + std::to_string(random);
	}
	
}

std::string unit::getIa()
{
	return _iaCode.c_str();
}

unit* unit::operator*(const unit &r) const {
	int random = rand() % 2;
	unit* utwo = new unit();

	if (random == 0) {
		utwo->_iaCode = r._iaCode;
	}
	else {
		utwo->_iaCode = _iaCode;
	}

	std::vector<int> _levelsMax;
	for (int i = 0; i < _listCapacity.size(); ++i)
	{
		_levelsMax.push_back((r._listCapacity[i]->getLevel() > _listCapacity[i]->getLevel()) ? r._listCapacity[i]->getLevel() : _listCapacity[i]->getLevel());
	}
	
	int givenLevels = 0;

	utwo->_Id = _Id;

	while (givenLevels < r._unitLevel)
	{
		random = rand() % 7;
		if ((utwo->getCapacity(random).getLevel() + 1) <= _levelsMax[random])
		{
			utwo->getCapacity(random).upgrade();
			utwo->_unitLevel++;
			givenLevels++;
		}
	}

	return utwo;
}