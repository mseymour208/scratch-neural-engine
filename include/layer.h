#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include "math_utils.h"

using namespace std;

class layer {

private:
    matrix W, b, dW, db, A_prev, Z, A;

public:

    layer(int n_in, int n_out);
    matrix forward_pass(const matrix& input_A);
    matrix backward_pass(const matrix& dA);

};




#endif