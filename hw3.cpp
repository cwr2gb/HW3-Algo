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

using namespace std;
double distance(double a, double b, double c, double d);
double bruteF(vector<Point> p);
double getShortest(vector<Point> p, vector<Point> q);
vector<Point> points;
vector<Point> pointsX;
vector<Point> pointsY;
vector<double> sortX;
vector<double> sortY;
double minDistance = 10001;

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

    cout << endl;
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
    
    //Prints Points
    cout << "Points" << endl;
    for(vector<Point>::iterator a = points.begin(); a != points.end(); ++a){
      cout << a->getX() << "," << a->getY() << endl;
    }
    
    //Prints Points with x-coords increasing
    cout << "PointsX" << endl;
    for(vector<Point>::iterator b = pointsX.begin(); b != pointsX.end(); ++b){
      cout << b->getX() << "," << b->getY() << endl;
    }
    
    //Prints Points with y-coords increasing
    cout << "PointsY" << endl;
    for(vector<Point>::iterator c = pointsY.begin(); c != pointsY.end(); ++c){
      cout << c->getX() << "," << c->getY() << endl;
    }
    
   // cout << getShortest(left,right) << endl;
    
    points.clear();
    pointsX.clear();
    pointsY.clear();
    sortX.clear();
    sortY.clear();

  }
}

double distance(double a, double b, double c, double d){
  return pow((pow((a-c),2)-pow((b-d),2)),.5);
}

/*double getShortest(vector<Point> p, vector<Point> q){
  if(p.size() == 1 && q.size() == 1){
    return distance(p.getX(),p.getY(),q.getX(),q.getY());
  }
  else if(p.size() == 2 && q.size()==1){
  }
  else if(q.size() == 2 && p.size()==1){
  }
  else{ 
   vector<Point> l(store.begin(),store.begin()+store.size()/2);
   vector<Point> r(store.begin()+store.size()/2,store.end());
    return getShortest(l,r) ;
  }
}*/

double bruteF(vector<Point> p){
  for(vector<Point>::const_iterator p = points.begin(); p != points.end(); ++p){      
  }
}