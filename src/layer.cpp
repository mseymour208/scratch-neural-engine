#include "layer.h"


layer::layer(int n_in, int n_out) : W(n_out, n_in, n_in, n_out), b(n_out, 1) {}

matrix layer::forward_pass(const matrix& input_A) {
    A_prev = input_A;
    Z = (W & A_prev) + b;
    A = math_utils::sigmoid(Z);

    return A;
}

matrix layer::backward_pass(const matrix& dA) {
    matrix dZ = dA % math_utils::sigmoid_deriv(A);
    dW = dZ & !A_prev;

    db = dZ;
    matrix dA_prev = !W & dZ;

    return dA_prev;
}
