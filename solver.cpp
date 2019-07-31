#include "matrix.h"
#include "equation.h"
#include "term.h"


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
  Matrix* a = new Matrix(6,2);
  a->printMat();
//  a->hello();
}


//create coefficient matrix based on an array of equations
//Matrix* makeCoeffMat(Equation**){

//}


void solveEquation(){
  int size = getInputSize();
  Equation** eqs = new Equation*[size];
  for(int i = 0; i< size; i++){
    Equation* x = new Equation(getInputEQ(), size);
    eqs[i] = x;
  }
  float val;
  Matrix* co = new Matrix(size, size+1);
  for(int r = 0; r<size; r++){
    for(int c = 0; c<size; c++){
      val = eqs[r]->getTerms()[c]->getCoefficient();
      co->setMat(r, c, val);
    }
  }
  for(int k = 0; k<size; k++){
    co->setMat(k,size, eqs[k]->con);
  }
  Matrix* ans = co->rref();
  char variable;
  for (int j = 0; j < size; j++){
    variable = eqs[j]->getTerms()[j]->varName;
    val = ans->get(j, size);
    cout << variable << " = " << val << endl;
  }
}
