#include "matrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Matrix::Matrix(int size){
  m_size = size;

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

void Matrix::hello(){
  cout<<"hello from matrix.cpp"<< endl;
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


// bool isID(float** matrix, int size){
//   for(int i =0; i<size; i++){
//     for(int j=0; j<size; j++){
//       if(i==j && matrix[i][j]!=1.0){
//         return false;
//       }
//       if(i!=j && matrix[i][j]!=0){
//         return false;
//       }
//     }
//   }
//   return true;
// }
