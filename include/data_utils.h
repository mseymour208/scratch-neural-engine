#ifndef DATA_UTILS_H
#define DATA_UTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "matrix.h"

namespace data_utils {

    void load_csv(const string& filepath, vector<matrix>& X, vector<matrix>& Y, int label_idx);

}


#endif