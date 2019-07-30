#include "equation.h"
#include "term.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Equation::Equation(string eq, int size){
  cout<<"Making equation!"<<endl;
  m_eq = eq;
  m_size = size;
  m_terms = new Term*[m_size];
  int frm = 0;
  int to = 0;
  int count = 0;
  while(to<eq.length()){
    if((eq.at(to)=='+'||eq.at(to)=='-') && to!=0){
      cout<<"to: "<<to<<"frm: "<< frm<<endl;
      cout<<"term substr"<<eq.substr(frm, to-frm)<<endl;
      m_terms[count] = new Term(eq.substr(frm, to-frm));
      count++;
      frm = to;
    }
    else if(eq.at(to)=='='){
      m_terms[count] = new Term(eq.substr(frm, to-frm));
      count++;
      frm = to+1;
      to = eq.length();
      cout<<"substr: "<< eq.substr(frm, to-frm)<<endl;
      con = stof(eq.substr(frm, to-frm));
      cout<<"to: "<<to<<"frm: "<< frm<<endl;
    }
    to++;
  }
}


void Equation::printEq(){
  cout<<m_eq<<endl;
}
