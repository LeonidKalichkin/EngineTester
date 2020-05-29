#pragma once
#include "../engine/Engine.h"
class Testbed
{
public:
	virtual int run(Engine &engine);
	virtual double getTimePassed();
};

