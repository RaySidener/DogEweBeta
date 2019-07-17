#pragma once

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
    char* vars; //array of variables
    float* vals; //array of values corresponding with variables
    string m_eq; //string of the equation
};
