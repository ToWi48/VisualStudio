#include <iostream>
#include <math.h>

using namespace std;


class tvector2 
{
private:
	double x,y;

public:
	tvector2() // default constructor
	{
		x = 0;
		y = 0;
	}
	tvector2(double a, double b) // constructor
	{
		x = a;
		y = b;
	}

	double length()
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	tvector2 operator /(const tvector2& a) const
	{
		cout << x << " / " << a.x << endl;
		cout << y << " / " << a.y << endl;
		return tvector2(x + a.x, y + a.y);
	}
};

int main()
{
	cout << "Hallo Tom :)" << endl;

	tvector2 a = tvector2(1, 2);
	tvector2 b = tvector2(11, 22);
	tvector2 res = a / b / a;

	cout << res.length() << endl;

	return 0;
}