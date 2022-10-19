#include "Animal.h"

void Animal::setType(int _type)
{
	type = _type;
}

int Animal::getType()
{
	return type;
}

bool Animal::isError()
{
	return this->error;
}

void Animal::setError(bool _error)
{
	this->error = _error;
}

Animal::~Animal()
{
}