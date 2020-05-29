#pragma once
class Environment
{
private:
	double temperature;
		
public:
	Environment(double temperature);
	double getTemperature();
	void setTemperature(double temperature);
};