#include "solver.cpp"
#include "matrix.h"
#include "matrix.cpp"
#include "equation.h"
#include "equation.cpp"
#include "term.h"
#include "term.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

int main(){
  cout<<"Welcome to DogEweBeta, a system of equation solver!"<<endl;
  while(1){
    solveEquation();
    cout<<"You can keep going, or hit ctrl-c to quit"<<endl;
  }
  return 0;
}
