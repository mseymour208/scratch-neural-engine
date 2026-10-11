#include "matrix.h"

matrix::matrix(int r, int c) {
    vector<double> v(r * c);
    tuple shape = (r, c);
}

matrix::matrix(int r, int c, int n_in, int n_out) {
    vector<double> v;

    // Xavier initialization
    double limit = sqrt(6/(n_in + n_out));
    
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> dist(-limit, limit);

    for(int i = 0; i < r*c; i++) {
        v[i] = dist(gen);
    }

}

void matrix::operator+(matrix m) {
    for (int i = 0; i < m.vec.size(); i++) {
            this->vec[i] = this->vec[i] + m.vec[i];
        }
}




