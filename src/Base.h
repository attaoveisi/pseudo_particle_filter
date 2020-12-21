#ifndef SRC_BASE_H
#define SRC_BASE_H

#include <random> //C++ 11 Random Numbers
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <stdexcept> // throw errors

class Base {
public:
    Base() = default;
    virtual ~Base() = default;
    double mod(double first_term, double second_term);
    double gen_real_random();
    double max(std::vector<double> arr, int n);
};

#endif //SRC_BASE_H
