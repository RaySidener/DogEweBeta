#include "matrix.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Matrix::Matrix(int size, int width){
  m_size = size;
  if(width==-1){
    m_width = size;
    isSquare = true;
  }
  else{
    m_width = width;
    isSquare = false;
  }
    m_matrix = new float*[m_size];
    for(int i = 0; i<size; i++){
      m_matrix[i] = new float[m_width];
    }
    setMat();
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
  cout<<"Matrix: "<< endl;
  cout<< "{";
  for (int i = 0; i<m_size; i++){
    for(int j = 0; j<m_width; j++){
      cout<<m_matrix[i][j] <<", ";
    }
    cout<<""<<endl;
  }
  cout<<"}"<< endl;
}

bool Matrix::isID(){
  if(!isSquare){
    return false;
  }
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

bool Matrix::hasSolutions(){
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
  else if (isSquare){
    for(int i = 0;i<m_size; i++){
      for(int j = 0; j<m_size; j++){
        m_matrix[i][j] = 0;
        if(i==j){
          m_matrix[i][j] = 1;
        }
      }
    }
  }
  else {
    for(int i = 0; i<m_size;i++){
      for(int j = 0; j<m_width; j++){
        m_matrix[i][j] = 0;
      }
    }
  }
}

void Matrix::byConst(int row, float k, float* arr){
  if(arr==NULL){
    for(int i = 0; i<m_width; i++){
      m_matrix[row][i] *=k;
    }
  }
  else {
    for(int i = 0; i<m_width; i++){
      arr[i] =m_matrix[row][i]*k;
    }
  }
}

void Matrix::swapRow(int row1, int row2){
  float temp;
  for(int i = 0; i<m_width; i++){
    temp = m_matrix[row1][i];
    m_matrix[row1][i] = m_matrix[row2][i];
    m_matrix[row2][i] = temp;
  }
}

void Matrix::add(int row, float* arr){
  for(int i = 0; i<m_width; i++){
    m_matrix[row][i]+=arr[i];
  }
}


//returns the rref of matrix
Matrix* Matrix::rref(){
  Matrix* cp  = new Matrix(m_size, m_width);
  float pivot;//value of the pivot
  int tmp;
  float front;
  float* multiples = new float[m_width];
  for(int l = 0; l<m_size;l++){
    for(int k = 0; k<m_width; k++){
      cp->setMat(l,k,m_matrix[l][k]);
    }
  }
  int i = 0;
  int j = 0;


  while(i<m_size&&j<m_width){
      pivot = cp->get(i,j);
      tmp = i+1;
      if(pivot==0){
        while(pivot==0 && tmp<m_size){
          pivot = cp->get(tmp, j);
          tmp++;
        }
        if(pivot==0){//column is all 0s
          j++;
        }
        else{
          cp->swapRow(tmp-1,i);
        }//step 1
        //reset pivot
        pivot = cp->get(i,j);
      }
      cp->byConst(i,(1/pivot));
      //step 2
      for(int m = 0; m<m_size; m++){
        front = cp->get(m,j);
        if(front!=0 && m!=i){
          cp->byConst(i, (-1*front), multiples);
          cp->add(m, multiples);
        }//step 3
      }
      i++;
      j++;
    }


  return cp;
}
