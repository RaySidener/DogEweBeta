#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Matrix {

public:
  Matrix::Matrix(int size);

  void Matrix::hello();
  void Matrix::printMat();
  bool Matrix::isID();
  float** Matrix::rref();
  void Matrix::setMat(int row=-1, int col=-1, float val=0);


private:
   float** m_matrix;
   int m_size;
   
   void Matrix::swapRow(int row1, int row2);
   void Matrix::swapCol(int col1, int col2);
   void Matrix::byConst(int row, float k, float* arr = NULL);

};
