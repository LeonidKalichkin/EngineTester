#include "Utils.h"

double Utils::interpolate(double x, std::vector<double> xs, std::vector<double> ys)
{
	double current;
	unsigned int before = 0, after = UINT_MAX;
	for (unsigned int i = 0; i < xs.size(); i++)
	{
		current = xs[i];
		if (x < current)
		{
			after = i;
			break;
		}
	}

	if (after == UINT_MAX)
	{
		return ys[ys.size() - 1];
	}
	else if (after == 0)
	{
		return ys[0];
	}
	else
	{
		before = after - 1;
	}

	double a1 = (ys[after] - ys[before]) / (xs[after] - xs[before]);
	double a0 = ys[before] - a1 * xs[before];
	return a0 + a1 * x;
}
