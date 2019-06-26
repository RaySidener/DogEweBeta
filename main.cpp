#include "solver.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

int main(){
  const int size = 2;
  float** mat;
  mat = new float*[size];
  makeMatrix(mat, size);

  rref(mat);
  printMat(mat,size);
  add(0,2);
  return 0;
}
