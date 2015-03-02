#pragma once
#include "capacity.h"
#include "point.h"
#include "health.h"
#include "speedCapacity.h"
#include "armorCapacity.h"
#include "reloadSpeedCapacity.h"
#include "regenCapacity.h"
#include "damageCapacity.h"
#include "rangeCapacity.h"
#include <vector>
#include <list>

/*
	Une unité peut fournir :  
	● un identifiant unique (int getId())  
	● un accès à chaque capacité via son nom (méthodes SpeedCapacity& getSpeed(), HealthCapacity&  getHealth(), etc…)  
	● un accès à chaque capacité via son index 0 ­> vitesse, 1 ­> points de vie, etc...  (opérateur [])  
	● son niveau global (méthode int getLevel())  
	● sa position (méthode Point getPosition())
	*/

class unit
{
private:
	std::vector<capacity*> _listCapacity;
	int _Id;
	int _reloadTime;
	point _unitPosition;
	std::string _iaCode;

	

	/*
	Les actions d’une unité sont :   
	● rafraichir ses informations (méthode void refresh())  
		○ mettre la valeur de la vie a max(valeur max de vie, valeur de vie +  regeneration)   
		○ décrémenter le temps de latence avant son prochain tir  

	● changer de position (méthode void setPosition())  
	● tirer (méthode bool shoot()) :   
		○ si temps de latence est à 0, mettre temps de latence au maximum et retourne  vrai  
			○ sinon retourne faux   
	● prendre des dommages (méthode void takeDamage(float value) ) :  
		○ diminuer la valeur de la vie de (value ­ valeur armure)  

	● indiquer qu’elle est encore en vie (méthode bool isAlive()):  
		○ si la valeur de la vie est inférieure ou égale à 0, retourner faux  
		○ sinon retourner vrai 

   Les constructeurs demandés  pour une unité sont les suivants :   
   ● un seul paramètre de type int, représentant le niveau global de l’unité, les niveaux  seront alors répartis aléatoirement entre les capacités, et on attribuera une IA  aléatoirement.  
   ● un code IA, et un paramètre entier pour chaque capacité, correspondant au niveau de  celle ci.
	*/

public:
	unit();
	unit(int level,int Id);
	unit(std::string _iaCode, std::vector<int> _levelsCapacity);
	unit(const unit *u);
	~unit();

	void intializeUnit();
	capacity& getCapacity(int index);
	speedCapacity& getSpeed();
	health& getHealth();
	armorCapacity& getArmor();
	rangeCapacity& getRange();
	damageCapacity& getDamage();
	regenCapacity& getRegen();
	reloadSpeedCapacity& getReload();
	int getunitLevel();
	point getPosition();
	void setPosition(const point& p);
	void mutate();

	void refresh();
	bool isAlive();
	bool shoot();
	void takeDamage(float value);

	int getId();
	void giveLevelToCapacity();
	void giveIa();
	std::string getIa();

	unit* operator*(const unit &r) const;

	int _unitLevel;
};

std::ostream& operator<<(std::ostream&, unit&);

