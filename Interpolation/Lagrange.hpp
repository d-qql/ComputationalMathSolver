//
// Created by Demia on 13.09.2021.
//

#ifndef INTERPOLATOR_LAGRANGE_H
#define INTERPOLATOR_LAGRANGE_H
#include <cmath>
#include <iostream>
#include <vector>
#include "../Template/Template.hpp"

class Lagrange {
private:
    std::vector<double> x;
    std::vector<double> y;

    double l(double x, int k) const;

public:
    Lagrange(const std::vector<double> &x,
             const std::vector<double> &y);
    Lagrange(const Template& aTemplate);
    double interpolate(double x) const;


};


#endif //INTERPOLATOR_LAGRANGE_H
