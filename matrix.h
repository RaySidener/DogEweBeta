#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Matrix {

public:
  //initializes m_size and m_matrix to ID
  //width is optional and only needs to be set for non-square matrices
  Matrix::Matrix(int size, int width = -1);

  void Matrix::hello();//used for testing
  void Matrix::printMat();
  bool Matrix::isID();
  Matrix* Matrix::rref();//uses the Gauss-Jordan algorithm to calculate the rref
  //sets matrix i,j to val. if used without params, sets to ID for square matrices or to all 0s for non-square
  void Matrix::setMat(int row=-1, int col=-1, float val=0);
  float Matrix::get(int row, int col){return m_matrix[row][col];}
  bool Matrix::hasSolutions(); //given a matrix in rref, does that matrix represent a solution?


private:
   float** m_matrix;
   int m_size;//height
   int m_width;
   bool isSquare;

   //swaps the contents of row1 and row2 in m_matrix
   void Matrix::swapRow(int row1, int row2);
   //multiplies row 'row' by k. if arr is included save result there
   void Matrix::byConst(int row, float k, float* arr = NULL);
   void Matrix::add(int row, float* arr); //adds the contents of arr to the rowth row of the matrix

};
