#include "matrix.h"
#include "equation.h"
#include "term.h"


#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


//TODO: add error handling
int getInputSize(){
  int x;
  cout<<"How many variables?"<<endl;
  cin >> x;
  return x;
}

string getInputEQ(){
  string eq;
  cout<<"Input equation: ";
  cin>>eq;
  return eq;
}

void helloSolver(){
  cout<<"hello from solver.cpp"<<endl;
  Matrix* a = new Matrix(6,2);
  a->printMat();
//  a->hello();
}

char* getCharSet(Equation** eq, int size){
  char* charSet = new char[size];
  int count = 0;
  char toAdd;
  bool cont;
  for (int i = 0; i< size; i++){
    for (int j = 0; j<size; j++){
      toAdd = eq[i]->getTerms()[j]->varName;
      cont = false;
      if(toAdd=='.'){
        cont = true;
      }
      else { //check if charSet has toAdd already
        for (int k = 0; k<size; k++){
          if(charSet[k]==toAdd){
            cont = true;
          }
        }
      }

      if (!cont){
        charSet[count] = toAdd;
        count++;
      }
      if(count==size){
        return charSet;
      }
    }
  }
  return charSet;
}

//make sure variables are in the right order and all there
void alignEQs(Equation** eq, int size){
  char* vars = getCharSet(eq, size);//standard order of variables in eqs
  bool ordered;
  int toSwap;
  int swapWith;
//adds 0 terms to equations
  for (int i = 0; i<size; i++){
    for (int j = 0; j<size; j++){
      if (eq[i]->containsTerm(vars[j])<0){
        //honestly not really sure what to do here... does this work?
        eq[i]->getTerms()[eq[i]->termsFilled]->varName = vars[j];
        eq[i]->termsFilled++;
      }
    }
  }
//rearranges terms as needed in equation
  for (int k = 0; k<size; k++){
    for(int l = 0; l<size; l++){
      //maybe - put this in a separate loop?
      //TODO: change containsTerm so it returns index of that
      if(eq[k]->getTerms()[l]->varName!=vars[l]){//order of variables in equation is out of whack
        ordered = false;
        toSwap = l;
        while(!ordered){
          //use containsTerm to get index in eq[i] of that term
          swapWith = eq[k]->containsTerm(vars[toSwap]);
          //then swapterms(j, index)
          //now check- is index in the right place?
          //if not, swap so that it is in the right place
          eq[k]->swapTerms(toSwap, swapWith);
          //if index is in the right place
          if (eq[k]->getTerms()[swapWith]->varName==vars[swapWith]){
            ordered = true;
          }
          else {
            toSwap = swapWith;
          }

        }
      }
    }
  }
}



//create coefficient matrix based on an array of equations
Matrix* makeCoeffMat(Equation** eqs, int size){
  Matrix* mat = new Matrix(size, size+1);
  float val;
  for(int r = 0; r<size; r++){
    for(int c = 0; c<size; c++){
      val = eqs[r]->getTerms()[c]->coefficient;
      mat->setMat(r, c, val);
    }
  }
  for(int k = 0; k<size; k++){
    mat->setMat(k,size, eqs[k]->con);
  }
  return mat;
}


void solveEquation(){
  int size = getInputSize();
  Equation** eqs = new Equation*[size];
  for(int i = 0; i< size; i++){
    Equation* x = new Equation(getInputEQ(), size);
    eqs[i] = x;
  }
  alignEQs(eqs, size);
  Matrix* co = makeCoeffMat(eqs, size);
  Matrix* ans = co->rref();
  if (ans->hasSolutions()){
    char variable;
    float val;
    for (int j = 0; j < size; j++){
      variable = eqs[j]->getTerms()[j]->varName;
      val = ans->get(j, size);
      cout << variable << " = " << val << endl;
    }
  }
  else{
   cout<< "No solution :("<<endl;
  }
}
