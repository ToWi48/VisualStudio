#pragma once

// 08.07.21-1

#include<string>
#include "vector.h";
#include <tuple>

using namespace std;
typedef tuple<string, string, int> Tssi;

class vehicle
{
private:
	string name;
	string desc;
	int age;
	vector2 position;

public:
	vehicle();
	vehicle(string name, string desc, int age);
	vector2 getPosition();
	Tssi getInfo();
};

class trailer : vehicle
{
private:
	double level;
	int animation;

public:
	trailer();
	trailer(double level, int animation);
	void fill(double v);
	void tip();
};

