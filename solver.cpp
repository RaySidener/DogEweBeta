#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

void rref(float** matrix){
  cout<<"putting in reduced row echelon form";
}

//sets up 2d array size x size matrix
//and initializes it to I
void makeMatrix(float** mat, int size){
  for(int i = 0; i<size; i++){
    mat[i] = new float[size];
  }
  for(int j = 0; j<size;j++){
    for(int k = 0; k< size; k++){
      mat[j][k] = 0;
      if(j==k){
        mat[j][k] = 1;
      }
    }
  }
}

//prints matrix, assumed square size x size
void printMat(float** matrix, int size){
  cout<<"Matrix: "<< endl;
  cout<< "{";
  for (int i = 0; i<size; i++){
    for(int j = 0; j<size; j++){
      cout<<matrix[i][j] <<", ";
    }
    cout<<""<<endl;
  }
  cout<<"}"<< endl;;
}

int add(int a, int b){
  cout<<"we out here";
  return a+b;
}
