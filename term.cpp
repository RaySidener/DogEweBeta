#include "term.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

Term::Term(string t){
  isNegative = false;
  m_term = t;
  string t2 = t.substr(0, t.length()-1);

  varName = t.at(t.length()-1);
  if(t2=="+"||t2==""){
    coefficient = 1;
  }
  else if(t2=="-"){
    coefficient = -1;
  }
  else {
    coefficient = stof(t2);
  }
}


void Term::printTerm(){
  cout<<m_term<<endl;
}
