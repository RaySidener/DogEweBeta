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

  rref(mat, size);
  printMat(mat,size);
  printMat(rref(mat, size), size);
  return 0;
}
