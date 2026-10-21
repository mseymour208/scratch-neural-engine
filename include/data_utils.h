#ifndef DATA_UTILS_H
#define DATA_UTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <cfloat>
#include <algorithm>

#include "matrix.h"

namespace data_utils {

    void load_csv(const string& filepath, vector<matrix>& X, vector<matrix>& Y, int label_idx);
    void train_test_split(vector<matrix>& X, vector<matrix>& Y, vector<matrix>& X_train, vector<matrix>& X_test, vector<matrix>& Y_train, vector<matrix>& Y_test);
}


#endif