#ifndef NETWORK_H
#define NETWORK_H

#include "layer.h"
#include "gradient_descent.h"

class network {

private:
    vector<layer> layers;
    gradient_descent optimizer;

public:
    network(int a);
    void add_layer(int n_in, int n_out);

    void train(vector<matrix>& X, vector<matrix>& Y, int epochs);

};


#endif