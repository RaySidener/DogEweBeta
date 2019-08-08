#include "equation.h"
#include "term.h"
#include "helpers.cpp"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Equation::Equation(string eq, int size){
  m_eq = eq;
  m_size = size;
  m_terms = new Term*[m_size];
  int frm = 0;
  int to = 0;
  int count = 0;
  while(to<eq.length()){
    if((eq.at(to)=='+'||eq.at(to)=='-') && to!=0){
      m_terms[count] = new Term(eq.substr(frm, to-frm));
      count++;
      frm = to;
    }
    else if(eq.at(to)=='='){
      m_terms[count] = new Term(eq.substr(frm, to-frm));
      count++;
      frm = to+1;
      to = eq.length();
      con = stof(eq.substr(frm, to-frm));
    }
    to++;
  }
  termsFilled = count;
  for (int i = count; i<size; i++){
    cout<<"prepping yeet..."<<endl;
    m_terms[count] = new Term("EMPTY");
  }
  cout<<"YEET"<<endl;
}


void Equation::printEq(){
  cout<<m_eq<<endl;
}

void Equation::swapTerms(int i, int j){
  cout<< "Swapping terms "<< i<<", "<< j<<endl;
  char tmp = m_terms[i]->varName;
  m_terms[i]->varName = m_terms[j]->varName;
  m_terms[j]->varName = tmp;

  float val = m_terms[i]->coefficient;
  m_terms[i]->coefficient = m_terms[j]->coefficient;
  m_terms[j]->coefficient = val;
}

int Equation::containsTerm(char var){
  for (int i = 0; i < m_size; i++){
    if(m_terms[i]->varName==var){
      return i;
    }
  }
  return -1;
}
