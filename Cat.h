#pragma once
#include "Animal.h"
class Cat :
    public Animal
{
	string species;
	string color;
	string user;
	string name;
public:
	Cat();
	Cat(ifstream& fin);
	~Cat();
	void edit();
	void save(ofstream& fout);
	void print(ostream& out);
};

