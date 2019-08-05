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

//make sure variables are in the right order and all there
void alignEQs(Equation** eq, int size){
  char* vars = new char[size];
  cout<<"alles gutes"<<endl;
}


//create coefficient matrix based on an array of equations
Matrix* makeCoeffMat(Equation** eqs, int size){
  Matrix* mat = new Matrix(size, size+1);
  float val;
  for(int r = 0; r<size; r++){
    for(int c = 0; c<size; c++){
      val = eqs[r]->getTerms()[c]->getCoefficient();
      mat->setMat(r, c, val);
    }
  }
  for(int k = 0; k<size; k++){
    mat->setMat(k,size, eqs[k]->con);
  }
  return mat;
}


void solveEquation(){
  int size = getInputSize();
  Equation** eqs = new Equation*[size];
  for(int i = 0; i< size; i++){
    Equation* x = new Equation(getInputEQ(), size);
    eqs[i] = x;
  }
  alignEQs(eqs, size);
  Matrix* co = makeCoeffMat(eqs, size);//new Matrix(size, size+1);
  co->printMat();
  Matrix* ans = co->rref();
  char variable;
  float val;
  for (int j = 0; j < size; j++){
    variable = eqs[j]->getTerms()[j]->varName;
    val = ans->get(j, size);
    cout << variable << " = " << val << endl;
  }
}
