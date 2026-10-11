#include "math_utils.h"



matrix math_utils::sigmoid(const matrix& m) {
    matrix z(m.row, m.col);
    for (int i = 0; i < m.vec.size(); i++) {
        z.vec[i] = (1)/(1 + exp(-m.vec[i]));
    }
    return z;
}

matrix math_utils::sigmoid_deriv(const matrix& m) {

}

double math_utils::BCE_cost(const matrix& Y, const matrix& A) {

}

matrix math_utils::BCE_deriv(const matrix& Y, const matrix& A) {

}