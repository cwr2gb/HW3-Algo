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
#include <math.h>

using namespace std;
double distance();
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
  vector<Point>* points = new vector<Point>;
  vector<double> *sorting = new vector<double>;
  while (num_cases != 0){
    file >> num_cases;
    int numcases = 0;

    while(numcases < num_cases){
      file >> xcoord;
      file >> ycoord;
      Point add = Point(xcoord,ycoord);  
      points->push_back(add);
      sorting->push_back(xcoord);
      numcases++;
    }

    cout << endl;
    //Sorts values
    sort(sorting->begin(),sorting->end());
   
    vector<Point> *store = new vector<Point>;
   
    for(vector<double>::const_iterator y = sorting->begin(); y != sorting->end(); ++y){
      for(vector<Point>::const_iterator z = points->begin(); z != points->end(); ++z){        
	if(*y == z->getX() && store->size() < points->size()){
	  Point add2 = Point(z->getX(),z->getY());
	  store->push_back(add2);
        }
      }
    }
    for(vector<Point>::iterator a = store->begin(); a != store->end(); ++a){
      cout << a->getX() << "," << a->getY() << endl;
    }
  
    sorting->clear();
    points->clear();
    store->clear();
  }
}

double distance(double a, double b, double c, double d){
  return pow((pow((a-c),2)-pow((b-d),2)),.5);
}