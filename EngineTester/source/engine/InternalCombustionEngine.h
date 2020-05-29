#pragma once
#include "Engine.h"
#include <vector>
class InternalCombustionEngine :
    public Engine
{
private:
    double temperature;
    double torque = 0;
    double rotationalSpeed = 0;
    double momentOfInertia = 0;
    std::vector<double> torqueRelations = {};
    std::vector<double> rotationalSpeedRelations = {};
    double heatingRateToTorque = 0;
    double heatingRateToRotationalSpeed = 0;
    double coolingRate = 0;
public:
    InternalCombustionEngine(Environment &env, double momentOfInertia, std::vector<double> torqueRelations, std::vector<double> rotationalSpeedRelations,
        double heatingRateToTorque, double heatingRatetoRotationalSpeed, double coolingRate);
    virtual void run(double time) override;
    virtual void start() override;
    virtual void stop() override;
    virtual double getTemperature() override;
    static double interpolate(double x, std::vector<double> xs, std::vector<double> ys);
};

