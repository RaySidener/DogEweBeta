#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Matrix {

public:
  Matrix::Matrix(int size, int width = -1);

  void Matrix::hello();
  void Matrix::printMat();
  bool Matrix::isID();
  Matrix* Matrix::rref();
  void Matrix::setMat(int row=-1, int col=-1, float val=0);
  float Matrix::get(int row, int col){return m_matrix[row][col];}
  void Matrix::add(int row, float* arr);
  bool Matrix::hasSolutions();
//  void Matrix::setConst(float** );


private:
   float** m_matrix;
//   float** m_const;
   int m_size;
   int m_width;
   bool isSquare;

   void Matrix::swapRow(int row1, int row2);
   void Matrix::byConst(int row, float k, float* arr = NULL);

};
