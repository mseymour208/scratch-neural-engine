#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include "matrix.h"
#include <cmath>

namespace math_utils {

    matrix sigmoid(const matrix& m);
    matrix sigmoid_deriv(const matrix& m);
    double BCE_cost(const matrix& Y, const matrix& A);
    matrix BCE_deriv(const matrix& Y, const matrix& A);

}

#endif