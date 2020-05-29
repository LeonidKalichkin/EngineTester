#include "OverheatTestbed.h"

OverheatTestbed::OverheatTestbed(double overheatTemperature, double timeLimit, double timestep)
{
	this->overheatTemperature = overheatTemperature;
	this->timeLimit = timeLimit;
	this->timestep = timestep;
}

int OverheatTestbed::run(Engine &engine)
{
	timePassed = 0;
	engine.start();

	while (engine.getTemperature() < overheatTemperature)
	{
		if (timePassed >= timeLimit)
		{
			engine.stop();
			return 1;
		}
		engine.run(timestep);
		timePassed += timestep;
	}

	engine.stop();
	return 0;
}

double OverheatTestbed::getTimePassed()
{
	return timePassed;
}
