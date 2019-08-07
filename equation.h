#pragma once

#include "term.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Equation {

  public:
    Equation::Equation(string eq, int size);
    void Equation::printEq();
    Term** getTerms(){return m_terms;}
    float con = NULL;
    int Equation::containsTerm(char var);
    int termsFilled;//number of terms actually defined
    void Equation::swapTerms(int i, int j);



  private:
    int m_size; //number of variables in equation
    string m_eq; //string of the equation
    Term** m_terms;

};
