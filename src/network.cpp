#include "network.h"


network::network(double a) : optimizer(a) {}

void network::add_layer(int n_in, int n_out) {
    layer new_layer(n_in, n_out);
    layers.push_back(new_layer);
}

void network::train(vector<matrix>& X, vector<matrix>& Y, int epochs) {
    // Loop epochs times
    // Loop through each example in X and Y
    // Network prediction matrix with forward
    // Get initial dA
    // Reverse loop through layers with backward
    // update layers

    
}


