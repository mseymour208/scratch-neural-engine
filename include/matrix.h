#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>
#include <random>
using namespace std;


class matrix;
namespace math_utils {
    matrix sigmoid(const matrix& m);
    matrix sigmoid_deriv(const matrix& m);
    double BCE_cost(const matrix& Y, const matrix& A);
    matrix BCE_deriv(const matrix& Y, const matrix& A);
}

namespace data_utils {
    void load_csv(const string& filepath, vector<matrix>& X, vector<matrix>& Y, int label_idx);
}


class matrix {

private:
    vector<double> vec;
    int row;
    int col;

public:
    // Overload
    // addition, subtraction, scalar/dot product, transposition, random, printing
    matrix();
    matrix(int r, int c); // 0's initialize (bias)
    matrix(int r, int c, const vector<double>& data);
    matrix(int r, int c, int n_in, int n_out); // random initialize (weights)

    matrix operator+(const matrix& m) const;
    matrix operator-(const matrix& m) const;
    matrix operator*(double s) const;
    matrix operator&(const matrix& m) const;
    matrix operator!() const;
    matrix operator%(const matrix& m) const;
    double operator()(int r, int c) const;

    friend void data_utils::load_csv(const string& filepath, vector<matrix>& X, vector<matrix>& Y, int label_idx);

    friend matrix math_utils::sigmoid(const matrix& m);
    friend matrix math_utils::sigmoid_deriv(const matrix& m);
    friend double math_utils::BCE_cost(const matrix& Y, const matrix& A);
    friend matrix math_utils::BCE_deriv(const matrix& Y, const matrix& A);
    
    friend ostream& operator<<(ostream& os, const matrix& m);

};



#endif