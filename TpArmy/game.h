#pragma once
#include "army.h"
#include <iostream>

class game
{
	/*B ­ 
	Déroulement d’une confrontation d’armées  Au départ on a nos deux armées.
	Tant que les deux armées ont au moins une unité :  
	● on récupère la liste d’unités de chaque armée  
	● pour chaque unité, prise de façon aléatoire  : 
		○ on lance son IA  ○ on applique l’action demandée en retour de l’IA 
		○ on lance la purge de l’armée adverse  Le score de l’armée perdante est 0.
	Le score de l’armée gagnante est le nombre d’unités à la fin de la confrontation.
	Un affichage décrivant ce qu’il se passe doit être effectué à chaque tour, par exemple en  utilisant la syntaxe suivante  :
	== == == == == == = Tour 14  == == == == == == == == = 
	Unité 23 (Armée A)  attaque Unité 3 (Armée B) qui n’a plus que 54 HP 
	Unité 2 (Armée B) bouge en position (10, 562)
		Les scores finaux doivent s’afficher également sur la sortie standard.*/
private:
	army* ArmyA;
	army* ArmyB;
	int turns;

public:
	game();
	game(army* a, army* b);
	~game();

	void play(int maxTurns);

	void deploiement();
	void appendTurn();
	void setTime();
	int calculateDist(unit a, unit b);
	void askForIa(unit& a, army* targetA, int f);
	point& move(unit& a, unit& b, int f);
	bool checkifAllAlivemethod();

};

