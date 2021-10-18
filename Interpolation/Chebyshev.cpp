//
// Created by d-qql on 19.10.2021.
//

#include "Chebyshev.hpp"

std::vector<double> ChebyshevRoots(double a, double b, int n) {
    std::vector<double> result;
    for (int i = 0; i < n; ++i) {
        result.push_back(std::cos(M_PI * (i + 0.5) / n));
        result[result.size() - 1] *= (b - a) / 2.;
        result[result.size() - 1] += (a + b) / 2.;
    }

    return result;
}


