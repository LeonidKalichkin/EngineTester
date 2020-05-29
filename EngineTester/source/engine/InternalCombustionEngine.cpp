#include "InternalCombustionEngine.h"
#include <iostream>
#include "../util/Utils.h"

InternalCombustionEngine::InternalCombustionEngine(Environment &env, double momentOfInertia, std::vector<double> torqueRelations,
	std::vector<double> rotationalSpeedRelations, double heatingRateToTorque, double heatingRateToRotationalSpeed, double coolingRate) : Engine(env)
{
	this->momentOfInertia = momentOfInertia;
	this->torqueRelations = torqueRelations;
	this->rotationalSpeedRelations = rotationalSpeedRelations;
	this->heatingRateToTorque = heatingRateToTorque;
	this->heatingRateToRotationalSpeed = heatingRateToRotationalSpeed;
	this->coolingRate = coolingRate;
}

void InternalCombustionEngine::run(double time)
{
	//считаем, что скорость нагрева и охлаждения двигателя установились в начале исследуемого шага времени работы двигателя и существенно не изменялись
	double heating = torque * heatingRateToTorque + rotationalSpeed * rotationalSpeed * heatingRateToRotationalSpeed;
	double cooling = coolingRate * (getEnvironment()->getTemperature() - temperature);

	temperature += (heating + cooling) * time;

	double acceleration = torque / momentOfInertia;
	rotationalSpeed += acceleration * time;
	torque = Utils::interpolate(rotationalSpeed, rotationalSpeedRelations, torqueRelations);
}

void InternalCombustionEngine::start()
{
	temperature = Engine::getEnvironment()->getTemperature();
	rotationalSpeed = 0;
	torque = Utils::interpolate(rotationalSpeed, rotationalSpeedRelations, torqueRelations);
}

void InternalCombustionEngine::stop()
{
	torque = 0;
	rotationalSpeed = 0;
}

double InternalCombustionEngine::getTemperature()
{
	return temperature;
}