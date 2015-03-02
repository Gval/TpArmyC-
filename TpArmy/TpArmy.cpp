// TpArmy.cpp : Defines the entry point for the console application.

//

#include "stdafx.h"
#include "unit.h"
#include "army.h"
#include "game.h"
#include <iostream>
#include <vector>					// for vector class
#include <string>					// for string class
#include <algorithm>				// for sort algorithm
#include <time.h>					// for random seed
#include <math.h>					// for abs()
#include <fstream>
#include <sstream>

#define GA_POPSIZE		10		// ga population size
#define GA_MAXITER		50		// maximum iterations
#define GA_ELITRATE		0.10f		// elitism rate
#define GA_MUTATIONRATE	0.25f		// mutation rate
#define GA_MUTATION		RAND_MAX * GA_MUTATIONRATE

void init_population(std::vector<army*> &population,
	std::vector<army*> &buffer, int numbreArm, int numbrUnit, int numbrLevels)
{
	int tsize = 10;

	for (int i = 0; i<numbreArm; i++) {
		army* citizen = new army(numbrUnit, numbrLevels);
		citizen->score = 0;
		population.push_back(citizen);
	}

}

void calc_fitness(std::vector<army*> &population)
{
	unsigned int fitness;

	for (int i = 0; i<population.size(); i++) {
		for (int j = 0; j < population.size(); j++) {
			if (j == i){

			}
			else {
				game gamu(population[i], population[j]);
				gamu.play(125);
			}
				
		}
	}
}

bool fitness_sort(army* x, army* y)
{
	return (x->score > y->score);
}

inline void sort_by_fitness(std::vector<army*> &population)
{
	sort(population.begin(), population.end(), fitness_sort);
}

void elitism(std::vector<army*> &population,
	std::vector<army*> &buffer, int esize)
{
	for (int i = 0; i<esize; i++) {
		buffer.push_back(new army(population[i]->getUnitList()));
	}
}

void mate(std::vector<army*> &population, std::vector<army*> &buffer)
{
	int esize = population.size() * 0.1f;
	int randPopSide = population.size()*0.3f;
	int i2;

	elitism(population, buffer, esize);

	// Mate the rest
	for (int i = 0; i<randPopSide; i++) {

		i2 = rand() % (population.size() - randPopSide);

		army * arm = new army();
		arm->score = 0;
		std::vector<unit*> _unitList;
		for (int j = 0; j < population[0]->getUnitList().size();  ++j) {
			_unitList.push_back(population[i]->getUnit(j) * population[i2]->getUnit(j));
		}
		arm->setUnitList(_unitList);
		buffer.push_back(arm);

		army * arm2;
		arm2 = &population[i]->mutate();
		buffer.push_back(arm2);

		buffer.push_back(new army(population[0]->getUnitList().size(), population[0]->getUnitList()[0]->_unitLevel));
		//if (rand() < GA_MUTATION) mutate(buffer[i]);
	}

	
}

inline void swap(std::vector<army*> &population,
	std::vector<army*> &buffer)
{
	population = buffer; 
	buffer.clear();
}

inline void print_best(std::vector<army*> &gav, int f)
{
	std::cout << "Best of iteration : " << f << std::endl;
	/*for (int i = 0; i < gav.size(); ++i)
	{*/
		for (int j = 0; j < gav[0]->getUnitList().size(); ++j)
		{
			std::cout << gav[0]->getUnit(j) << std::endl;
		}
	//}
	
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand(unsigned(time(NULL)));

	/*1. L’utilisateur choisi 5 valeurs entières I, T, N, X, et Y.  
	2. On génère aléatoirement N armées de X unités avec chacune un niveau global de Y.  
	3. On fait I fois*/
	int maxIter, numberArmys, numberUnits, LevelUnits;
	
	std::string input;

	std::cout << "Combiens d'iterations ?" << std::endl;
	getline(std::cin, input);
	std::stringstream myStream(input);
	myStream >> maxIter;

	std::cout << "Combiens d'armees ?" << std::endl;
	getline(std::cin, input);
	std::stringstream myStream2(input);
	myStream2 >> numberArmys;

	std::cout << "Combiens d'unites ?" << std::endl;
	getline(std::cin, input);
	std::stringstream myStream3(input);
	myStream3 >> numberUnits;

	std::cout << "Combiens de niveaux ?" << std::endl;
	getline(std::cin, input);
	std::stringstream myStream4(input);
	myStream4 >> LevelUnits;


	std::vector<army*> listArmy, listArmyB;

	std::vector<army*> _listArmy;
	std::vector<army*> _listArmyB;

	init_population(listArmy, listArmyB,numberArmys,numberUnits,LevelUnits);
	_listArmy = listArmy;
	_listArmyB = listArmyB;

	for (int i = 0; i<maxIter; i++) {
		calc_fitness(_listArmy);		// calculate fitness
		sort_by_fitness(_listArmy);	// sort them
		print_best(_listArmy, i);		// print the best one

		mate(_listArmy, _listArmyB);		// mate the population together
		swap(_listArmy, _listArmyB);		// swap buffers
	}

	std::ofstream file;
	std::string filename = "army_" + std::to_string(10) + "_" + std::to_string(20) + ".save";
	file.open(filename);
	for (int i = 0; i < _listArmy[0]->getUnitList().size(); ++i)
	{
		file << _listArmy[0]->getUnit(i) << std::endl;
	}
	file.close();
	return 0;
}