#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Term {

  public:
    Term::Term(string t);
    void Term::printTerm();
    float getCoefficient(){return coefficient;}

    string m_term;
    char varName;
    bool isNegative;
  private:
    float coefficient;//coefficient of term not including +/-

};
