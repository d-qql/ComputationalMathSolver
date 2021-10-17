//
// Created by Demia on 14.09.2021.
//

#include "Newton.h"
#include <algorithm>
#include <cmath>
#include <iostream>

Newton::Newton(const Template &aTemplate) {
    this->x = aTemplate.x;
    this->y = aTemplate.y;
    diff.resize(this->x.size());
    int N = this->x.size() - 1;
    diff.back() = difference(N, 0, N);
    diff[0] = y[0];
}

double Newton::difference(double k, int first, int last) {
    if (k == 1) {
        return (y[last] - y[first]) / (x[last] - x[first]);
    }
    double left = difference(k - 1, first + 1, last);
    double right = difference(k - 1, first, last - 1);
    diff[k - 1] = right;
    return (left - right) /
           (x[last] - x[first]);

}

double Newton::interpolate(double t) {
    double result = 0;
    double complex;
    for (int i = 0; i < diff.size(); ++i) {
        complex = 1;
        for (int k = 0; k < i; k++) {
            complex *= (t - this->x[k]);
        }
        result += diff[i] * complex;

    }
    return result;

}

Newton::Newton(const std::vector<double> &x, const std::vector<double> &y) : x(x), y(y) {}






