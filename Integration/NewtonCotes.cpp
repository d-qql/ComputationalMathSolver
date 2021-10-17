//
// Created by d-qql on 17.10.2021.
//

#include "NewtonCotes.hpp"

double NewtonCotes::trapeze(const std::vector<double> &x, std::function<double(double)> function) {

    double result = 0;
    for (int i = 1; i < x.size(); ++i) {
        result += (function(x[i - 1]) + function(x[i])) / 2. * (x[i] - x[i - 1]);
    }
    return result;
}

double NewtonCotes::sympson(const std::vector<double> &x, std::function<double(double)> function) {
    double result = 0;
    for (int i = 1; i < x.size(); ++i) {
        result += (function(x[i - 1]) + 4 * function((x[i - 1] + x[i]) / 2.) + function(x[i])) / 6. * (x[i] - x[i - 1]);
    }
    return result;
}

double NewtonCotes::three_eights(const std::vector<double> &x, std::function<double(double)> function) {
    double result = 0;
    for (int i = 1; i < x.size(); ++i) {
        result += (function(x[i - 1]) + 3 * function((2 * x[i - 1] + x[i]) / 3.) +
                   3 * function((x[i - 1] + 2 * x[i]) / 3.) + function(x[i])) / 8. * (x[i] - x[i - 1]);
    }
    return result;
}

double NewtonCotes::trapeze(double a, double b, int n, std::function<double(double)> function) {
    double h = (b - a) / n;
    double result = 0;
    for (int i = 1; i <= n; ++i) {
        result += (function(a + (i - 1) * h) + function(a + i * h)) / 2. * ((a + i * h) - ((i - 1) * h + a));
    }
    return result;
}

double NewtonCotes::sympson(double a, double b, int n, std::function<double(double)> function) {
    double h = (b - a) / n;
    double result = 0;
    for (int i = 1; i <= n; ++i) {
        result += (function(a + (i - 1) * h) + 4 * function((a + i * h + a + (i - 1) * h) / 2.) + function(a + i * h)) /
                  6. *
                  (a + i * h - (a + (i - 1) * h));
    }
    return result;
}

double NewtonCotes::three_eights(double a, double b, int n, std::function<double(double)> function) {
    double h = (b - a) / n;
    double result = 0;
    for (int i = 1; i <= n; ++i) {
        result += (function(a + (i - 1) * h) + 3 * function((2 * (a + (i - 1) * h) + a + i * h) / 3.) +
                   3 * function((a + (i - 1) * h + 2 * (a + i * h)) / 3.) + function(a + i * h)) / 8. *
                  (a + i * h - (a + (i - 1) * h));
    }
    return result;
}
