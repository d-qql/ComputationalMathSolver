//
// Created by Demia on 14.09.2021.
//

#ifndef INTERPOLATOR_NEWTON_H
#define INTERPOLATOR_NEWTON_H
#include <cmath>
#include <iostream>
#include <vector>
#include "../Template/Template.hpp"
#include <functional>
#include "Chebyshev.hpp"
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
    Newton(double a, double b, int n, std::function<double(double)> function);
    double interpolate(double x);
    void get_polynomial() const;

};


#endif //INTERPOLATOR_NEWTON_H
