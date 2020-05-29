#pragma once
#include "Testbed.h"
class OverheatTestbed :
    public Testbed
{
private:
    double overheatTemperature;
    double timeLimit;
    double timestep;
    double timePassed = 0;
public:
    OverheatTestbed(double overheatTemperature, double timeLimit, double timestep);
    virtual int run(Engine &engine) override;
    virtual double getTimePassed() override;
};

