#include "Engine.h"

Engine::Engine(Environment &env)
{
	this->env = &env;
}

Environment* Engine::getEnvironment()
{
	return this->env;
}

void Engine::setEnvironment(Environment &env)
{
	this->env = &env;
}

void Engine::start() {}

void Engine::stop() {}

void Engine::run(double time) {}

double Engine::getTemperature()
{
	return temperature;
}

void Engine::setTemperature(double temperature)
{
	this->temperature = temperature;
}
