#include "Coordinate.h"
#include <cmath>

using std::to_string;
using std::sqrt;
using std::pow;

Coordinate::Coordinate(double x, double y, double z) : x(x), y(y), z(z)
{
}

double Coordinate::distanceTo(Coordinate* another)
{
    return sqrt(pow(x - another->x, 2) + pow(y - another->y, 2)  + pow(z - another->z, 2));
}
