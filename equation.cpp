#include "equation.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Equation::Equation(string eq, int size){
  cout<<"Making equation!"<<endl;

  m_eq = eq;
  m_size = size;
  vars = new char[m_size];
  vals = new float[m_size];
  //TODO: parse through input string and populate arrays
  //are these arrays the best way to do this? or is there a better way?
  for(int i = 0; i < m_eq.length(); i++){
    cout<<m_eq.at(i);
  }
}


void Equation::printEq(){
  cout<<m_eq<<endl;
}
