    #include "matrix.h"
    #include "network.h"
    #include "data_utils.h"


    int main() {

        // X and Y data containers
        vector<matrix> X;
        vector<matrix> Y;

        // Load data using breast cancer data set
        data_utils::load_csv("C:\\Users\\Mikle\\OneDrive\\Desktop\\scratch-neural-engine\\breast+cancer+wisconsin+diagnostic.zip", X, Y, 1);


        // Creating network

        network neural_net(0.1); // Learning rate 0.1
        neural_net.add_layer(30, 16); // Hidden Layer
        neural_net.add_layer(16, 1); // Output Layer

        neural_net.train(X, Y, 100);
        int count = 0;
        for (int i = 0; i < X.size(); i++) {
            int temp = 0;
            if (neural_net.predict(X[i])(0, 0) >= 0.5) {
                temp = 1;
            }

            if (temp == Y[i](0, 0)) {
                count += 1;
            }
        }
        cout << (count * 100.0) / X.size();


    }