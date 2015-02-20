#ifndef POINT_H
#define POINT_H

#include <iostream>

using namespace std;

class Point {
public:
  Point(double x, double y);               
  double getX() const;
  double getY() const;
  double xCo, yCo;

 private:
  
};

#endif
