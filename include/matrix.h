#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <tuple>
#include <random>
using namespace std;

class matrix {

private:
    vector<double> vec;
    tuple<int, int> shape;

public:
    // Overload
    // addition, subtraction, scalar/dot product, transposition, random, printing
    matrix(int r, int c); // 0's initialize (bias)
    matrix(int r, int c, int n_in, int n_out); // random initialize (weights)

    void operator+(matrix m);


};



#endif