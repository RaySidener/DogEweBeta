#include "matrix.h"
#include "equation.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


//TODO: add error handling
int getInputSize(){
  int x;
  cout<<"How many variables?"<<endl;
  cin >> x;
  return x;
}

string getInputEQ(){
  string eq;
  cout<<"Input equation: ";
  cin>>eq;
  return eq;
}

void helloSolver(){
  cout<<"hello from solver.cpp"<<endl;
  Matrix* a = new Matrix(3);
  a->hello();
}


//create coefficient matrix based on an array of equations
//Matrix* makeCoeffMat(Equation**){

//}


void solveEquation(){
  int size = getInputSize();
  for(int i = 0; i< size; i++){
    getInputEQ();
  }
}
