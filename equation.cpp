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
}


void Equation::printEq(){
  cout<<m_eq<<endl;
}
