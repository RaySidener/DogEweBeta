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

    string m_term;
    char varName;
    bool isNegative;
    float coefficient;//coefficient of term

};
