#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include "layer.h"
#include "math_utils.h"

class gradient_descent {

private:
    double alpha;

public:
    gradient_descent(double alpha);
    void update(layer& l);

};



#endif