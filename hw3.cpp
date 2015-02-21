//Charles Regan
//cwr2gb
//hw3.cpp
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "Point.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <cmath>
#include <iomanip>
using namespace std;
//Prototypes
double distance(double a, double b, double c, double d);
double bruteF(vector<Point> p);
double getShortest(vector<Point> p);
//Vectors for points
vector<Point> points;
vector<Point> pointsX;
vector<Point> pointsY;
vector<double> sortX;
vector<double> sortY;
//Min Distance variable
double minDistance = 10001;
double realMinDistance = 0;
double leftMin;
double rightMin;
double wholeMin;

int main(int argc, char **argv){
  
  // verify the correct number of parameters
  if ( argc != 2 ) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }
  
  // attempt to open the supplied file
  ifstream file(argv[1]);
  
  // report any problems opening the file and then exit
  if ( !file.is_open() ) {
    cout << "Unable to open file '" << argv[1] << "'." << endl;
    exit(2);
  }
  
  int num_cases = 1;
  double xcoord, ycoord;  
  FILE *fp = fopen(argv[1], "r");
  
  while (num_cases != 0){
    file >> num_cases;
    int numcases = 0;

    while(numcases < num_cases){
      file >> xcoord;
      file >> ycoord;
      Point add = Point(xcoord,ycoord);  
      points.push_back(add);
      sortX.push_back(xcoord);
      sortY.push_back(ycoord);
      numcases++;
    }

    //Sorts X values
    sort(sortX.begin(),sortX.end());
   
    for(vector<double>::const_iterator y = sortX.begin(); y != sortX.end(); ++y){
      for(vector<Point>::const_iterator z = points.begin(); z != points.end(); ++z){        
	if(*y == z->getX() && pointsX.size() < points.size()){
	  Point add2 = Point(z->getX(),z->getY());
	  pointsX.push_back(add2);
        }
      }
    }
    //Sorts Y values
    sort(sortY.begin(),sortY.end());
   
    for(vector<double>::const_iterator w = sortY.begin(); w != sortY.end(); ++w){
      for(vector<Point>::const_iterator x = points.begin(); x != points.end(); ++x){        
	if(*w == x->getY() && pointsY.size() < points.size()){
	  Point add2 = Point(x->getX(),x->getY());
	  pointsY.push_back(add2);
        }
      }
    } 
    
    /*Prints Points
    cout << "Points" << endl;
    for(vector<Point>::iterator a = points.begin(); a != points.end(); ++a){
      cout << a->getX() << "," << a->getY() << endl;
    }*/
    
    /*Prints Points with x-coords increasing
    cout << "PointsX" << endl;
    for(vector<Point>::iterator b = pointsX.begin(); b != pointsX.end(); ++b){
      cout << b->getX() << "," << b->getY() << endl;
    }*/
    
    /*Prints Points with y-coords increasing
    cout << "PointsY" << endl;
    for(vector<Point>::iterator c = pointsY.begin(); c != pointsY.end(); ++c){
      cout << c->getX() << "," << c->getY() << endl;
    }*/
    
    if(numcases != 0){
      wholeMin = getShortest(points);
      minDistance = 10001;
      leftMin = getShortest(pointsX);
      minDistance = 10001;
      rightMin = getShortest(pointsY);
      
      if((wholeMin <= leftMin) && (wholeMin <= leftMin)){
	realMinDistance = wholeMin;
      }
      else if((leftMin <= wholeMin) && (leftMin <= rightMin)){
	realMinDistance = leftMin;
      }
      else if((rightMin <= leftMin) && (rightMin <= wholeMin)){
	realMinDistance = rightMin;
      }
      
      if(realMinDistance >= 10000){
	cout << "infinity" << endl;
      }
      else{
	cout << setprecision(4) << fixed << realMinDistance << endl;
      }
    }
    
    realMinDistance = 0;
    leftMin = 0;
    rightMin = 0;
    wholeMin = 0;
    minDistance = 10001;
    points.clear();
    pointsX.clear();
    pointsY.clear();
    sortX.clear();
    sortY.clear();
  }
}

double distance(double a, double b, double c, double d){
  return pow(abs(pow(abs(a-c),2)+pow(abs(b-d),2)),.5);
}

double getShortest(vector<Point> p){
  if(p.size() < 4){
    return bruteF(p);
  }
  else{ 
    size_t const half = p.size()/2;
    vector<Point> LS(p.begin(),(p.begin() + half));
    vector<Point> RS((p.begin() + half),p.end());
    double left = getShortest(LS);
    double right = getShortest(RS);
    if(left < minDistance){
      minDistance = left;  
    }
    else if(right < minDistance){
      minDistance = right;  
    }
    
    return minDistance;
  }
}

double bruteF(vector<Point> p){
  int count = 0;
  int count2 = 0;
  for(vector<Point>::iterator a = p.begin(); a != p.end(); ++a){
    count++;
    for(vector<Point>::iterator b = p.begin(); b != p.end(); ++b){ 
      count2++;
      if(count != count2){
	if(minDistance > distance(a->getX(), a->getY(), b->getX(), b->getY())){
	  minDistance = distance(a->getX(), a->getY(), b->getX(), b->getY());
	}
      }
    }
    count2 = 0;
  }
  return minDistance;
}
















