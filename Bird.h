#pragma once
#include "Animal.h"
class Bird :
    public Animal
{
	string species;
	string color;
	string food;
	string home;
public:
	Bird();
	Bird(ifstream& fin);
	~Bird();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};
