#include "vehicle.h"
#include <iostream>
using namespace std;

// Vehicle
vehicle::vehicle()
{

}

vehicle::vehicle(string s_name, string s_desc, int s_age)
{
	name = s_name;
	desc = s_desc;
	age = s_age;
}

vector2 vehicle::getPosition()
{
	return position;
}

Tssi vehicle::getInfo()
{
	Tssi info = Tssi(name, desc, age);
	return info;
}

// Trailer
trailer::trailer()
{

}

trailer::trailer(double s_level, int s_animation)
{
	level = s_level;
	animation = s_animation;
}

void trailer::fill(double v)
{
	level = v;
	cout << "trailer filled to " << level << "% !" << endl;
}

void trailer::tip()
{
	cout << "trailer from " << level << "% to 0% tiped!" << endl;
	level = 0;
}