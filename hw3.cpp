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

using namespace std;

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
  
  int num_cases;
  double xcoord, ycoord;  
  FILE *fp = fopen(argv[1], "r");
  vector<Point>* points = new vector<Point>;

  file >> num_cases;
  int numcases = 0;

  /*while(numcases < num_cases){
    file >> xcoord;
    file >> ycoord;
    Point add = new Point(xcoord,ycoord);  


    
    //Sorts values
    sort(sorting->begin(),sorting->end());
    vector<MoveComp> *final= new vector<MoveComp>;
    vector<MoveComp> *store2 = new vector<MoveComp>;
    int check = 0;
    for(std::vector<int>::const_iterator y = sorting->begin(); y != sorting->end(); ++y){
      for(std::vector<MoveComp>::const_iterator z = store->begin(); z != store->end(); ++z){        if(*y == z->getCost() && check < 1){
	  MoveComp add2 = MoveComp(z->getCost(),z->getComp());
	  final->push_back(add2);
	  check++;
        }
	else 
	  {
	    MoveComp add2 = MoveComp(z->getCost(),z->getComp());
	    store2->push_back(add2);  
	  }
      }
      check = 0;
      store->clear();
      for(std::vector<MoveComp>::const_iterator x = store2->begin(); x != store2->end(); ++x){
	MoveComp add2 = MoveComp(x->getCost(),x->getComp());
	store->push_back(add2);
      } 
      store2->clear();
      
    }
    //Prints values in ascending order
    for(std::vector<MoveComp>::const_iterator x = final->begin(); x != final->end(); ++x){
      std::cout << x->getComp() << " " << x->getCost() << endl;
    }
    
    //Goes to next case and empties the Vector
    numcases++;
  }*/
  
}
