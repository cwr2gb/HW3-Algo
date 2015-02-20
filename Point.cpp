//Point.cpp
#include "Point.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

//Constructor
Point::Point(double x, double y){
  xCo = x;
  yCo = y;
}
//Gets X
double Point::getX() const{
  return xCo;
}
//Gets Y
double Point::getY() const{
  return yCo;
}

