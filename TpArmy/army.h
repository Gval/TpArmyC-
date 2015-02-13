#pragma once
#include "unit.h"

/*
	Une armée peut fournir :   
		● la liste de ses unités (méthode std::vector<Unit*> getUnitsList())  
		● une de ses unités par son id (Unit& getUnit(int id) )  
		● son nombre d’unités (int size() )  
		● son unité la plus proche d’un point donné (Unit& getNearestUnit(const Point& p))  
		● son unité la plus éloignée d’un point donné (Unit& getFurtherUnit(const Point& p))  
		● celle a la valeur de capacité la plus basse (Unit& getLowestUnit(int capa_index))  
		● celle a la valeur de capacité la plus haute (Unit& getHiggestUnit(int capa_index))  

	Ses actions sont :   
		● purger les unités mortes (void purge())
		     
	Deux constructeurs sont requis :  
		● un prenant un nombre d’unités, et le niveau global (identique) pour chacune d’elle.  Dans ces cas la, on générera aléatoirement les Unités grâce au constructeur dédié. 
		● un prenant un vecteur d’Unités, qui sera recopié. 
*/
class army
{
private:
	std::vector<unit*> _unitList;
	

public:
	army();
	army(int unitNumber, int globalLevel);
	army(std::vector<unit*> unitList);
	~army();

	unit& getUnit(int id);
	void purge();

	std::vector<unit*> getUnitList();

	int size();
};

