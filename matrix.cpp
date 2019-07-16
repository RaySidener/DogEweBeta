#include "matrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Matrix::Matrix(){
cout<<"in constructor, made matrix"<<endl;
}

void Matrix::hello(){
  cout<<"hello from matrix.cpp"<< endl;
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
