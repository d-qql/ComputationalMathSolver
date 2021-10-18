//
// Created by Demia on 14.09.2021.
//

#ifndef INTERPOLATOR_NEWTON_H
#define INTERPOLATOR_NEWTON_H
#include <cmath>
#include <iostream>
#include <vector>
#include "../Template/Template.hpp"

class Newton {
private:
    std::vector<double> x;
    std::vector<double> y;
    std::vector<double> diff;

    double difference(double k, int first, int last);


public:
    Newton() = delete;
    Newton(const std::vector<double>& x, const std::vector<double>& y);
    Newton(const Template& aTemplate);

    double interpolate(double x);

};


#endif //INTERPOLATOR_NEWTON_H
