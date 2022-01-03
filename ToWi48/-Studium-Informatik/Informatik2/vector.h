#pragma once
class vector2
{
private:
	double x, y;
public:
	vector2();
	vector2(double x, double y); // x = x, y = y
	double* get();
	double length();

	//vector2 operator = (vector2 other)
	//vector2& operator+=(vector2 other)

	vector2 operator +(const vector2& a) const

	//vector2 y;
	//vector2 x = y + y;

	//vector2 x += y;
};
