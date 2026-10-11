#include "layer.h"


layer::layer(int n_in, int n_out) {
    // W, b, dW, db, A_prev, Z, A
    matrix W(n_in, n_out, n_in, n_out);
    matrix b(n_out, 1);
}

matrix layer::forward_pass(const matrix& input_A) {
    matrix A_prev = input_A;
    matrix Z = W & A_prev + b;
    matrix A = math_utils::sigmoid(Z);

    return A;
}

matrix layer::backward_pass(const matrix& dA) {
    matrix dZ = dA % math_utils::sigmoid_deriv(Z);
    matrix dW = dZ & !A_prev;

    matrix db = dZ;
    matrix dA_prev = !W & dZ;
}
