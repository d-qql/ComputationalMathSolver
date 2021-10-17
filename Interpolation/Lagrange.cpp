//
// Created by Demia on 13.09.2021.
//

#include "Lagrange.h"
#include <algorithm>
#include <cmath>
#include <iostream>

Lagrange::Lagrange(const std::vector<double> &x, const std::vector<double> &y) {
    this->x = x;
    this->y = y;
}

double Lagrange::l(double x, int k) const {
    double result = 1;
    for (int i = 0; i < this->x.size(); ++i) {
        if (i == k) continue;
        result *= (x - this->x[i]) / (this->x[k] - this->x[i]);
    }
    return result;
}

double Lagrange::interpolate(double x) const {
    if (!(this->x[0] <= x && this->x.back() >= x)) {
        std::cout << "Babushka perepolnilas\'" << std::endl;
        return 0;
    }
    int i = std::upper_bound(this->x.begin(), this->x.end(), x) - this->x.begin();
    if (std::abs(x - this->x[i]) < 1e-15 && i < this->x.size()) {
        return y[i];
    }
    if (std::abs(x - this->x[i - 1]) < 1e-15 && i > 0) {
        return y[i - 1];
    }
    double result = 0;
    for (int k = 0; k < this->x.size(); ++k) {
        result += l(x, k) * this->y[k];
    }
    return result;
}

Lagrange::Lagrange(const Template &aTemplate) {
    this->x = aTemplate.x;
    this->y = aTemplate.y;
}
