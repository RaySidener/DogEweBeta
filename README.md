# DogEweBeta
## A little like WolfRamAlpha, but the knockoff version

#### **What it does now**
- Basically, solves systems of linear equations for x equations/variables
  - Prompts user for equation metadata (ie, how many equations/variables?) and equations
  themselves
  - Creates an augmented matrix representing the system of equations
  - Puts the matrix in reduced row echelon form
  - Prints out the solution to the system

#### **Things I plan to add**
- Better formatted output
  - including output for systems with no solutions/multiple solutions
- More user inputs accepted, and error handling for bad input
  - Rearrange equations so they're ordered correctly for the matrix!
  - Handle equations with variables valued at 0!
    - EG, on input 2x+3z=12 within a three-variable system, we have a third variable with a coefficient of 0. So that equation should be stored more like 2x+0y+3z=12
  - Simplify equations that aren't already fully simplified!
- other fun mathy features?!
  - simplify expressions?
  - solve equations with one variable?
  - solve *quadratics??*??? (maybe someday)
