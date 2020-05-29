#pragma once
#include "../environment/Environment.h"
class Engine
{
private:
    Environment *env;
    double temperature = 0;
public:
    Engine(Environment &env);
    Environment* getEnvironment();
    void setEnvironment(Environment &env);
    virtual void start();
    virtual void stop();
    virtual void run(double time);
    virtual double getTemperature();
    virtual void setTemperature(double temperature);
};

