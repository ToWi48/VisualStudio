#pragma once

double powTom(double x, double y)
{
	double back = 1;
	for (int i = 1; i <= y; i++)
	{
		back = back * x;
	}
	return back;
}

double fabsTom(double x)
{
	double back = x;
	if (x < 0)
		back = back * -1;
	return back;
}