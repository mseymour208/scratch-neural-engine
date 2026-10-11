#include "matrix.h"
#include "network.h"


int main() {

    // XOR gate data

    vector<matrix> X;
    X.push_back(matrix(2, 1, {0.0, 1.0}));
    X.push_back(matrix(2, 1, {1.0, 0.0}));
    X.push_back(matrix(2, 1, {1.0, 1.0}));
    X.push_back(matrix(2, 1, {0.0, 0.0}));

    vector<matrix> Y;
    Y.push_back(matrix(1, 1, {1.0}));
    Y.push_back(matrix(1, 1, {1.0}));
    Y.push_back(matrix(1, 1, {0.0}));
    Y.push_back(matrix(1, 1, {0.0}));


    // Creating network

    network neural_net(0.1); // Learning rate 0.1
    neural_net.add_layer(4, 4); // Hidden layer
    neural_net.add_layer(4, 1); // Output layer

    neural_net.train(X, Y, 10000);
    for (int i = 0; i < X.size(); i++) {
        cout << neural_net.predict(X[i]);
    }


}