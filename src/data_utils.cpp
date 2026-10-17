#include "data_utils.h"

void data_utils::load_csv(const string& filepath, vector<matrix>& X, vector<matrix>& Y, int label_idx) {
    ifstream file(filepath);

    if (!file.is_open()) {
        cerr << "Error opening file" << endl;
        return;
    }

    string row_string = "";

    // Iterate over rows
    while (getline(file, row_string)) {
        vector<double> y_raw;
        vector<double> x_raw;

        stringstream stream(row_string);
        string cell_string;
        int current_col = 0;

        // Iterate over columns
        while (getline(stream, cell_string, ',')) {
            if (current_col == label_idx) {
                if (current_col == 1 && cell_string == "M")
                y_raw.push_back(1.0);

                else if (current_col == 1 && cell_string == "B")
                y_raw.push_back(0.0);

                else
                y_raw.push_back(stod(cell_string));
            } 
            else if (current_col == 0) {
                current_col++;
                continue;
            } else {
                x_raw.push_back(stod(cell_string));
            }
            current_col++;
        }

        X.emplace_back(matrix(x_raw.size(), 1, x_raw));
        Y.emplace_back(matrix(y_raw.size(), 1, y_raw));
    }

    vector<double> feature_max(30, -DBL_MAX);
    vector<double> feature_min(30, DBL_MAX);

    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j < 30; j++) {
            if (X[i].vec[j] < feature_min[j]) {
                feature_min[j] = X[i].vec[j];
            }

            if (X[i].vec[j] > feature_max[j]) {
                feature_max[j] = X[i].vec[j];
            }
        }
    }

    for (int i = 0; i < X.size(); i++) {
        for (int j = 0; j < 30; j++) {
            X[i].vec[j] = (X[i].vec[j] - feature_min[j]) / (feature_max[j] - feature_min[j] + 1e-9);
        }
    }



}