#include "matrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Matrix::Matrix(int size){
  m_size = size;
  m_matrix = new float*[size];
  for(int i = 0; i<size; i++){
    m_matrix[i] = new float[size];
  }
  for(int j = 0; j<size;j++){
    for(int k = 0; k< size; k++){
      m_matrix[j][k] = 0;
      if(j==k){
        m_matrix[j][k] = 1;
      }
    }
  }

cout<<"Successfully made " <<endl;//<<size<<"x"<<size<<" matrix."<<endl;
}

//good for testing
void Matrix::hello(){
  cout<<"hello from matrix.cpp"<< endl;
  printMat();
  for(int i = 0; i< m_size; i++){
    for(int j = 0; j<m_size; j++){
      setMat(i,j, i*3+j);
    }
  }
  printMat();
  swapRow(2,1);
  printMat();
  byConst(2,2);
  printMat();
  float* x = new float[m_size];
  byConst(0,3,x);
}

void Matrix::printMat(){
cout<<"in printmat"<<endl;
  cout<<"Matrix: "<< endl;
  cout<< "{";
  for (int i = 0; i<m_size; i++){
    for(int j = 0; j<m_size; j++){
      cout<<m_matrix[i][j] <<", ";
    }
    cout<<""<<endl;
  }
  cout<<"}"<< endl;
}

bool Matrix::isID(){
  for(int i =0; i<m_size; i++){
    for(int j=0; j<m_size; j++){
      if(i==j && m_matrix[i][j]!=1.0){
        return false;
      }
      if(i!=j && m_matrix[i][j]!=0){
        return false;
      }
    }
  }
  return true;
}

void Matrix::setMat(int row, int col, float val){
  if (row != -1){
    m_matrix[row][col] = val;
  }
}

void Matrix::byConst(int row, float k, float* arr){
  if(arr==NULL){
    for(int i = 0; i<m_size; i++){
      m_matrix[row][i] *=k;
    }
  }
  else {
    cout<<"BY CONST METHOD ";
    for(int i = 0; i<m_size; i++){
      arr[i] =m_matrix[row][i]*k;
      cout<<", "<<arr[i];
    }
  }
}

void Matrix::swapRow(int row1, int row2){
  float temp;
  for(int i = 0; i<m_size; i++){
    temp = m_matrix[row1][i];
    m_matrix[row1][i] = m_matrix[row2][i];
    m_matrix[row2][i] = temp;
  }
}

//wait, do i actually need to do this?
void Matrix::swapCol(int col1, int col2){


}

//returns the rref of matrix
float** Matrix::rref(){
  float** lMat;
  lMat = new float*[m_size];
  float** rMat;
  rMat = new float*[m_size];

  for(int i = 0; i<m_size; i++){
    rMat[i] = new float[m_size];
    lMat[i] = new float[m_size];
  }

  for(int j = 0; j<m_size;j++){
    for(int k = 0; k<m_size; k++){
      rMat[j][k] = 0;
      lMat[j][k] = m_matrix[j][k];
      if(j==k){
        rMat[j][k] = 1;
      }
    }
  }

  //cout<<isID(matrix, size);
  //while(!(isID(lMat))){
    //note: won't use methods from solver.cpp in solver.cpp, so
    //above line won't work. here, we'll do the same moves/multiplies/adds
    //to rows in lMat and rMat. eventually either lmat==ID or there's an error
    //(I'll need to add good error handling for systems of equations that
  //have no solution or multiple solutions)
//  }

  return rMat;
}
