#pragma once
#include "Animal.h"
class Fish :
    public Animal
{
	string species;
	string color;
	string food;
	public:
	Fish();
	Fish(ifstream & fin);
	~Fish();
	void edit();
	void save(ofstream & fout);
	void print(ostream & out);
	};

