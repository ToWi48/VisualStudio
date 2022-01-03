#include "vector.h"
#include <math.h>

vector2::vector2()
{
} 

vector2::vector2(double i, double j)
{
	x = i;
	y = j;
}

double* vector2::get()
{
	double ret[2] = { x,y };
	return ret;
}

double vector2::length()
{
	return sqrt(pow(x,2)+pow(y,2));
}

vector2 operator +(const vector2& a)
{
	return vector2(x + a.x, y + a.y);
}
