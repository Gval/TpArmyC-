#include "stdafx.h"
#include "game.h"
#include "stdlib.h"

game::game()
{
}

game::game(army* a, army* b) : ArmyA(a), ArmyB(b)
{
}

game::~game()
{
}

void game::play(int maxTurns)
{
	
	int randTakenUnit;
	bool turnA = false;
	bool turnB = false;

	bool checkIfAllAlive = true;
	deploiement();

	while (turns < maxTurns && checkIfAllAlive)
	{
		turnA = false;
		turnB = false;

		

		//std::cout << " ==== ==== Tour : " << turns << " ==== ==== " << std::endl;
		
		while (!turnA && (checkIfAllAlive)){
			randTakenUnit = rand() % ArmyA->getUnitList().size();
			if (ArmyA->getUnit(randTakenUnit).isAlive()) {
				askForIa(ArmyA->getUnit(randTakenUnit), ArmyB, 0);
				turnA = true;
			}
		}

		checkIfAllAlive = checkifAllAlivemethod();

		randTakenUnit = -1;

		while (!turnB && (checkIfAllAlive)){
			randTakenUnit = rand() % ArmyB->getUnitList().size();
			if (ArmyB->getUnit(randTakenUnit).isAlive()) {
				askForIa(ArmyB->getUnit(randTakenUnit), ArmyA, 1);
				turnB = true;
			}
		}

		checkIfAllAlive = checkifAllAlivemethod();
		
		//regarder si l'unité est vivante

		turns++;

		for (int i = 0; i < ArmyA->getUnitList().size(); ++i)
		{
			if (ArmyA->getUnit(i).isAlive()) {
				ArmyA->getUnit(i).refresh();
			}
		}
		
		for (int i = 0; i < ArmyB->getUnitList().size(); ++i)
		{
			if (ArmyB->getUnit(i).isAlive()) {
				ArmyB->getUnit(i).refresh();
			}
		}

		checkIfAllAlive = checkifAllAlivemethod();
		//refresh all units
		
	}
	int numberOfAalive = 0, numberOfBalive = 0;

	for (int i = 0; i < ArmyA->getUnitList().size(); ++i)
	{
		if (ArmyA->getUnit(i).isAlive()) {
			numberOfAalive++;
		}

	}
	for (int i = 0; i < ArmyB->getUnitList().size(); ++i)
	{
		if (ArmyB->getUnit(i).isAlive()) {
			numberOfBalive++;
		}
	}

	if (numberOfAalive > numberOfBalive) {
		numberOfBalive = 0;
	}
	else if (numberOfAalive == numberOfBalive) {
		numberOfAalive = 0;
		numberOfBalive = 0;
	}
	else {
		numberOfAalive = 0;
	}

	ArmyA->score += numberOfAalive;
	ArmyB->score += numberOfBalive;
	/*std::cout << "Il reste " << numberOfAalive << " Soldats vivants dans la A armee" << std::endl;
	std::cout << "Il reste " << numberOfBalive << " Soldats vivants dans la B armee" << std::endl;*/
	/*std::cout << "Score de l armee A " << ArmyA->score << std::endl;
	std::cout << "Score de l armee B " << ArmyB->score << std::endl;*/
	//calculer le score
}

void game::askForIa(unit& aU, army* targetA, int f) {
	char a[2];
	unit target;

	a[0] = aU.getIa().at(0);
	a[1] = aU.getIa().at(1);

	int num = (a[1] - '0') % 48;

	
	if (a[1] == 'D') {
		if (a[0] == 'L') {
			target = targetA->getNearestUnit(aU.getPosition());
		}
		else {
			target = targetA->getFurtherUnit(aU.getPosition());
		}
	}
	else {
		if (a[0] == 'L') {
			target = targetA->getLowestUnit(num);
		}
		else {
			target = targetA->getHiggestUnit(num);
		}
	}

	

	if (aU.getRange().getValue() > calculateDist(aU, target))
	{
		if (aU.shoot())
		{
			target.takeDamage(aU.getDamage().getValue());
			if (f == 0){
				//std::cout << " Armee A, unite " << aU.getId() << ", Attaque unite " << target.getId() << ", inflige " << aU.getDamage().getValue() - target.getArmor().getValue() << " dommages. Reste " << target.getHealth().getValue() << " PV " << std::endl;
			}
			else {
				//std::cout << " Armee B, unite " << aU.getId() << ", Attaque unite  " << target.getId() << ", inflige " << aU.getDamage().getValue() - target.getArmor().getValue() << " dommages. Reste " << target.getHealth().getValue() << " PV " << std::endl;
			}
		}
		
	}
	else {
		aU.setPosition(move(aU, target, f));
	}
}

void game::deploiement()
{
	int rand_x;

	for (int i = 0; i < ArmyA->getUnitList().size(); ++i)
	{
		rand_x = rand() % 25;
		ArmyA->getUnit(i).setPosition(point(rand_x, 0));
		ArmyA->getUnit(i).getHealth().setValue(ArmyA->getUnit(i).getHealth().getMaxValue());
	}

	for (int j = 0; j < ArmyB->getUnitList().size(); ++j)
	{
		rand_x = rand() % 25;
		ArmyB->getUnit(j).setPosition(point(rand_x, 25));
		ArmyB->getUnit(j).getHealth().setValue(ArmyB->getUnit(j).getHealth().getMaxValue());
	}
}

int game::calculateDist(unit a, unit b) {

	int xd = b.getPosition()._x - a.getPosition()._x;
	int yd = b.getPosition()._y - a.getPosition()._y;
	int sqrtss = sqrt((xd*xd) + (yd*yd));
	return sqrtss;
}

point& game::move(unit& a, unit& b, int f) {

	int pX = b.getPosition()._x - a.getPosition()._x;
	int pY = b.getPosition()._y - a.getPosition()._y;

	float signX = 0;
	float signY = 0;

	if (pX < 0)
	{
		signX = -1;
	}
	else {
		signX = 1;
	}


	if (pY < 0)
	{
		signY = -1;
	}
	else {
		signY = 1;
	}

	int newPX = a.getPosition()._x + (a.getSpeed().getValue() * signX);
	int newPY = a.getPosition()._y + (a.getSpeed().getValue() * signY);

	if (f == 0){
		/*std::cout << " Armee A, unite " << a.getId() << ", se deplace de : " << a.getPosition()._x << " x, " << a.getPosition()._y << " y." << std::endl;
		std::cout << " Vers : " << newPX << " x, " << newPY << " y." << std::endl;*/
	}
	else {
		/*std::cout << " Armee B, unite " << a.getId() << ", se deplace de : " << a.getPosition()._x << " x, " << a.getPosition()._y << " y." << std::endl;
		std::cout << " Vers : " << newPX << " x, " << newPY << " y." << std::endl;*/
	}

	return point(newPX,newPY);
}

bool game::checkifAllAlivemethod()
{
	bool check = false;

	for (int i = 0; i < ArmyA->getUnitList().size(); ++i)
	{
		if (ArmyA->getUnit(i).isAlive()) {
			ArmyA->getUnit(i).refresh();
			check = true;
		}
	}

	if (check){
		check = false;
	}
	else {
		return check;
	}

	for (int i = 0; i < ArmyB->getUnitList().size(); ++i)
	{
		if (ArmyB->getUnit(i).isAlive()) {
			ArmyB->getUnit(i).refresh();
			check = true;
		}
	}

	if (check){
		check = false;
	}
	else {
		return check;
	}

	return true;
}