#include "matrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int getInputSize(){
  int x;
  cout<<"How many variables?"<<endl;
  cin >> x;
  Matrix* a = new Matrix(x);
  a->printMat();
//  a->hello();
  return x;
}



void helloSolver(){
  cout<<"hello from solver.cpp"<<endl;
  Matrix* a = new Matrix(3);
  a->hello();
}
