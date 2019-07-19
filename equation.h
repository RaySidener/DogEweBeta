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

  private:
    int m_size; //number of variables in equation
    Term** m_terms;
    string m_eq; //string of the equation
};
