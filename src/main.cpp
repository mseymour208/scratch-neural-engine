    #include "matrix.h"
    #include "network.h"
    #include "data_utils.h"


    int main() {

        // X and Y data containers
        vector<matrix> X, Y;

        // Train/test containers
        vector<matrix> X_train, X_test, Y_train, Y_test;

        // Load data using breast cancer data set
        data_utils::load_csv("C:\\Users\\Mikle\\OneDrive\\Desktop\\scratch-neural-engine\\breast+cancer+wisconsin+diagnostic\\wdbc.data", X, Y, 1);
        data_utils::train_test_split(X, Y, X_train, X_test, Y_train, Y_test);

        // Creating network
        network neural_net(0.1); // Learning rate 0.1
        neural_net.add_layer(30, 16); // Hidden Layer
        neural_net.add_layer(16, 1); // Output Layer

        neural_net.train(X_train, Y_train, 1000);
        int count = 0;
        for (int i = 0; i < X_test.size(); i++) {
            int temp = 0;
            if (neural_net.predict(X_test[i])(0, 0) >= 0.5) {
                temp = 1;
            }

            if (temp == Y_test[i](0, 0)) {
                count += 1;
            }
            cout << (count * 100.0) / X_test.size() << endl;
        }


    }