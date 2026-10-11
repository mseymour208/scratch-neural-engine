#include "math_utils.h"

matrix math_utils::sigmoid(const matrix& m) {
    matrix z(m.row, m.col);
    for (int i = 0; i < m.vec.size(); i++) {
        z.vec[i] = (1.0)/(1.0 + exp(-m.vec[i]));
    }
    return z;
}

matrix math_utils::sigmoid_deriv(const matrix& m) {
    matrix z(m.row, m.col);
    for (int i = 0; i < m.vec.size(); i++) {
        z.vec[i] = m.vec[i] * (1.0 - m.vec[i]);
    }
    return z;
}

double math_utils::BCE_cost(const matrix& true_val, const matrix& y_hat) {
    double total_cost = 0.0;
    double epsilon = 1e-9;

    for (int i = 0; i < y_hat.vec.size(); i++) {
        double left = log(y_hat.vec[i] + epsilon) * true_val.vec[i];
        double right = (1.0 - true_val.vec[i]) * log(1.0 - y_hat.vec[i] + epsilon);

        total_cost += left + right;
    }

    total_cost *= -1;
    return total_cost /= y_hat.col;

}

matrix math_utils::BCE_deriv(const matrix& true_val, const matrix& y_hat) {
    matrix dA(true_val.row, true_val.col);
    double epsilon = 1e-9;

    for (int i = 0; i < y_hat.vec.size(); i++) {
        double left = (1.0 - true_val.vec[i]) / (1.0 - y_hat.vec[i] + epsilon);
        double right = (true_val.vec[i]) / (y_hat.vec[i] + epsilon);

        dA.vec[i] = left - right;
    }

    return dA;

}