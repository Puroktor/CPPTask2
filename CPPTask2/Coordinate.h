#pragma once
#include <string>

using std::string;

class Coordinate
{
private:
	double x;
	double y;
	double z;
public:
	Coordinate(double x, double y, double z);
	double distanceTo(Coordinate* another);
};

