#include "network.h"


network::network(double a) : optimizer(a) {}

void network::add_layer(int n_in, int n_out) {
    layers.emplace_back(n_in, n_out);
}

void network::train(vector<matrix>& X, vector<matrix>& Y, int epochs) {

    // Time loop
    for (int epoch = 0; epoch < epochs; epoch++) {
    
        // Data loop
        for (int i = 0; i < X.size(); i++) {
            matrix A = X[i];

            // Forward pass loop
            for (int k = 0; k < layers.size(); k++) {
                A = layers[k].forward_pass(A);
            }

            // Error gradient
            matrix dA = math_utils::BCE_deriv(Y[i], A);

            // Backward pass loop
            for (int j = layers.size() - 1; j >= 0; j--) {
                dA = layers[j].backward_pass(dA);
            }

            // Optimizer loop
            for (int o = 0; o < layers.size(); o++) {
                optimizer.update(layers[o]);
            }
        }


    }

}

matrix network::predict(const matrix& m) {
    matrix A = m;
    for (int i = 0; i < layers.size(); i++) {
        A = layers[i].forward_pass(A);
    }
    return A;
}


