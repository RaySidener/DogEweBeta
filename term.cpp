#include "term.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Term::Term(string t){
  cout<<"Making Term!"<<endl;
  isNegative = false;
  m_term = t;
  string t2 = t.substr(0, t.length()-1);
  cout<<"substr from term.cpp: "<< t2<<endl;
  // if (t.at(0)=='-'){
  //   isNegative = true;
  //   t2 = t.substr(1,t.length()-1);
  // }
  // else if(t.at(0)=='+'){
  //   t2 = t.substr(1,t.length()-1);
  // }
  varName = t.at(t.length()-1);
  coefficient = stof(t2);
}


void Term::printTerm(){
  cout<<m_term<<endl;
}
