#include "matrix.h"

matrix::matrix(int r, int c) : vec(r*c), row(r), col(c) {}

matrix::matrix(int r, int c, int n_in, int n_out) : vec(r*c), row(r), col(c) {

    // Xavier initialization
    double limit = sqrt(6/(n_in + n_out));
    
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> dist(-limit, limit);

    for(int i = 0; i < r*c; i++) {
        vec[i] = dist(gen);
    }


}

// Matrix addition
matrix matrix::operator+(const matrix& m) const {
    matrix z(m.row, m.col);
    for (int i = 0; i < m.vec.size(); i++) {
        z.vec[i] = this->vec[i] + m.vec[i];
    }

    return z;
}

// Matrix subtraction
matrix matrix::operator-(const matrix& m) const {
    matrix z(m.row, m.col);
    for (int i = 0; i < m.vec.size(); i++) {
        z.vec[i] = this->vec[i] - m.vec[i];
    }
    return z;
}

// Scalar multiplication
matrix matrix::operator*(double s) const {
    matrix z(this->row, this->col);
    for (int i = 0; i < this->vec.size(); i++) {
        z.vec[i] = this->vec[i] * s;
    }
    return z;
}

// Matrix multiplication
matrix matrix::operator&(const matrix& m) const {
    matrix z(this->row, m.col);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < m.col; j++) {
            for (int k = 0; k < this->col; k++) {
                z.vec[i * m.col + j] += this->vec[i * this->col + k] * m.vec[k * m.col + j];
            }
        }
    }

    return z;
}

// Element product
matrix matrix::operator%(const matrix& m) const {
    matrix z(this->row, this->col);
    for (int i = 0; i < this->vec.size(); i++) {
        z.vec[i] = this->vec[i] * m.vec[i];
    }
    return z;
}

// Transpose
matrix matrix::operator!() const {
    matrix z(this->col, this->row);
    for (int i = 0; i < this->row; i++) {
        for (int j = 0; j < this->col; j++) {
            z.vec[j * z.col + i] = this->vec[i * this->col + j];
        }
    }

    return z;
}

