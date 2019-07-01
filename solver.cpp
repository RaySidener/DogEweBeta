#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

//returns the rref of matrix
float** rref(float** matrix, int size){
  float** lMat;
  lMat = new float*[size];
  float** rMat;
  rMat = new float*[size];

  for(int i = 0; i<size; i++){
    rMat[i] = new float[size];
    lMat[i] = new float[size];
  }

  for(int j = 0; j<size;j++){
    for(int k = 0; k< size; k++){
      rMat[j][k] = 0;
      lMat[j][k] = matrix[j][k];
      if(j==k){
        rMat[j][k] = 1;
      }
    }
  }
  //while(!(isID(lMat))){
    //note: won't use methods from solver.cpp in solver.cpp, so
    //above line won't work. here, we'll do the same moves/multiplies/adds
    //to rows in lMat and rMat. eventually either lmat==ID or there's an error
    //(I'll need to add good error handling for systems of equations that
  //have no solution or multiple solutions)
//  }

  return rMat;
}

//returns true if it's I
bool isID(float** matrix, int size){
  for(int i =0; i<size; i++){
    for(int j=0; j<size; j++){
      if(i==j && matrix[i][j]!=1.0){
        return false;
      }
      if(i!=j && matrix[i][j]!=0){
        return false;
      }
    }
  }
  return true;
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
