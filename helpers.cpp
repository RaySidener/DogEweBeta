#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

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
