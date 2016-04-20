#include "Point.h"

Point:: Point() : x(0), y(0){};
Point:: Point(double x, double y) : x(x), y(y){};

double Point:: getX() const { return x;}
void Point:: setX(double x){ this->x = x;}

double Point:: getY() const { return y;}
void Point:: setY(double y){ this->y = y;}
