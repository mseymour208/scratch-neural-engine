#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <random>
using namespace std;

class matrix {

private:
    vector<double> vec;
    int row;
    int col;

public:
    // Overload
    // addition, subtraction, scalar/dot product, transposition, random, printing
    matrix(int r, int c); // 0's initialize (bias)
    matrix(int r, int c, int n_in, int n_out); // random initialize (weights)

    matrix operator+(const matrix& m) const;
    matrix operator-(const matrix& m) const;
    matrix operator*(double s) const;
    matrix operator&(const matrix& m) const;
    matrix operator!() const;
    matrix operator%(const matrix& m) const;

};



#endif