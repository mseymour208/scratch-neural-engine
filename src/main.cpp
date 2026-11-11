    #include "matrix.h"
    #include "network.h"
    #include "data_utils.h"
    #include <filesystem>

    namespace fs = filesystem;

    int main() {

        // X and Y data containers
        vector<matrix> X, Y;

        // Train/test containers
        vector<matrix> X_train, X_test, Y_train, Y_test;



        // Data loading...

        // File path
        string q = "Which dataset?: ";
        string a;
        cout << q;
        getline(cin, a);

        fs::path base_dir = R"(C:\Users\Mikle\OneDrive\Desktop\scratch-neural-engine\DATA)";
        fs::path full_path = base_dir / (a + ".csv");

        if (fs::exists(full_path)) {
            cout << "Loading: " << full_path.string() << "\n";
        } else {
            cerr << "Error: File not found at " << full_path.string() << "\n\n";
            exit(1);
        }


        // Label index
        q = "Label index?: ";
        int label_idx;
        cout << q;
        cin >> label_idx;
        
        // Text header
        q = "Does it have a text header? (T/F): ";
        bool has_header;
        cout << q;
        cin >> a;
        if (a == "T")
            has_header = true;
        else
            has_header = false;

        // ID index
        q = "ID index?: ";
        int id_idx;
        cout << q;
        cin >> id_idx;


        int num_features = data_utils::load_csv(full_path.string(), X, Y, label_idx, has_header, id_idx);

        // Breast Cancer dataset n = 569, 97.3684
        //data_utils::load_csv("C:\\Users\\Mikle\\OneDrive\\Desktop\\scratch-neural-engine\\DATA\\wdbc.data", X, Y, 1, false, 0);
        
        // Pima indians dataset n = 768, 86.3636
        //data_utils::load_csv("C:\\Users\\Mikle\\OneDrive\\Desktop\\scratch-neural-engine\\DATA\\\q.csv", X, Y, 8, false, -1);
        
        // Banknote authentication n = 1372, 99.6364  4
        //data_utils::load_csv("C:\\Users\\Mikle\\OneDrive\\Desktop\\scratch-neural-engine\\DATA\\BankNote_authentication.csv", X, Y, 4, true, -1);
        
        // Spambase n = 4601, 94.1368 2 minutes 30 s  57
        //data_utils::load_csv("C:\\Users\\Mikle\\OneDrive\\Desktop\\scratch-neural-engine\\DATA\\spambase.csv", X, Y, 57, true, -1);
        

        // Splitting data
        data_utils::train_test_split(X, Y, X_train, X_test, Y_train, Y_test);

        // Fit and transform our training data
        data_utils::MinMaxScaler scaler;
        scaler.fit_transform(X_train);
        scaler.transform(X_test);

        // Creating network
        network neural_net(0.1); // Learning rate 0.1
        neural_net.add_layer(num_features, 16); // Hidden Layer
        neural_net.add_layer(16, 1); // Output Layer


        // Train call
        neural_net.train(X_train, Y_train, 1000);

        cout << "Training Done" << endl;
        // Testing loop
        double total_bce = 0.0;
        const double eps = 1e-25;
        int count = 0;

        for (int i = 0; i < X_test.size(); i++) {

            double y_hat = neural_net.predict(X_test[i])(0, 0);
            double y_true = Y_test[i](0, 0);

            int pred_class = (y_hat >= 0.5) ? 1 : 0;
            if (pred_class == static_cast<int>(y_true)) {
                count++;
            }

            double p = max(eps, min(1.0 - eps, y_hat));
            total_bce += -(y_true * log(p) + (1.0 - y_true) * log(1.0 - p));

        }


        double accuracy = (count * 100.0) / X_test.size();
        double test_bce = total_bce / X_test.size();

        cout << "Test Accuracy: " << accuracy << "%" << endl;
        cout << "Test BCE Loss: " << test_bce << endl;

    }