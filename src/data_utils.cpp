#include "data_utils.h"
#include <unordered_map>

void data_utils::load_csv(const string& filepath, vector<matrix>& X, vector<matrix>& Y, int label_idx, bool has_header, int id_idx) {
    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    unordered_map<string, double> label_map;
    double class_counter = 0;

    string row_string = "";

    // Iterate over rows
    if (has_header) {
        getline(file, row_string);
    }
    while (getline(file, row_string)) {
        vector<double> y_raw;
        vector<double> x_raw;

        stringstream stream(row_string);
        string cell_string;
        int current_col = 0;

        // Iterate over columns
        while (getline(stream, cell_string, ',')) {
            if (current_col == label_idx) {

                if (label_map.find(cell_string) == label_map.end()) {
                    label_map[cell_string] = class_counter;
                    class_counter++;
                } 

                y_raw.push_back(label_map[cell_string]);
            }
            else if (current_col == id_idx) {
                current_col++;
                continue;
            } else {
                if (!cell_string.empty())
                    x_raw.push_back(stod(cell_string));
            }
            current_col++;
        }
        if (x_raw.size() > 0) {
            X.emplace_back(matrix(x_raw.size(), 1, x_raw));
            Y.emplace_back(matrix(y_raw.size(), 1, y_raw));
        }
    }

    if (!X.empty()) {
        vector<double> feature_max(X[0].row, -DBL_MAX);
        vector<double> feature_min(X[0].row, DBL_MAX);

        for (int i = 0; i < X.size(); i++) {
            for (int j = 0; j < X[0].row; j++) {
                if (X[i].vec[j] < feature_min[j]) {
                    feature_min[j] = X[i].vec[j];
                }

                if (X[i].vec[j] > feature_max[j]) {
                    feature_max[j] = X[i].vec[j];
                }
            }
        }

        for (int i = 0; i < X.size(); i++) {
            for (int j = 0; j < X[0].row; j++) {
                X[i].vec[j] = (X[i].vec[j] - feature_min[j]) / (feature_max[j] - feature_min[j] + 1e-9);
            }
        }
    }

}


void data_utils::train_test_split(vector<matrix>& X, vector<matrix>& Y, vector<matrix>& X_train, vector<matrix>& X_test,
vector<matrix>& Y_train, vector<matrix>& Y_test) {

    vector<int> indices;
    for (int i = 0; i < X.size(); i++) {
        indices.push_back(i);
    }

    random_device rd;
    mt19937 gen(rd());

    shuffle(indices.begin(), indices.end(), gen);
    int split_idx = X.size() * 0.8;

    int shuffled_idx = 0;
    for (int i = 0; i < X.size(); i++) {
        shuffled_idx = indices[i];
        if (i < split_idx) {
            X_train.push_back(X[shuffled_idx]);
            Y_train.push_back(Y[shuffled_idx]);
        } else {
            X_test.push_back(X[shuffled_idx]);
            Y_test.push_back(Y[shuffled_idx]);
        }
    }
}




