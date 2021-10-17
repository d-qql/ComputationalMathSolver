//
// Created by d-qql on 17.10.2021.
//

#include "Consts.hpp"

double norm(const std::vector<double> &a) {
    double sum = 0;
    for (size_t i = 0; i < a.size(); ++i) {
        sum += a[i] * a[i];
    }
    return sqrt(sum);
}
