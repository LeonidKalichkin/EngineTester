#include "Environment.h"

Environment::Environment(double temperature)
{
	this->temperature = temperature;
}

double Environment::getTemperature()
{
	return this->temperature;
}

void Environment::setTemperature(double temperature)
{
	this->temperature = temperature;
}
