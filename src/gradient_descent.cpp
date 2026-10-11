#include "gradient_descent.h"

gradient_descent::gradient_descent(double a) : alpha(a) {}

void gradient_descent::update(layer& l) {
    l.W = l.W - (l.dW * alpha);
    l.b = l.b - (l.db * alpha);

}