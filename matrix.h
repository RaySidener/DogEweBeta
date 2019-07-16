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


private:
   float** m_matrix;
   int m_size;


};
