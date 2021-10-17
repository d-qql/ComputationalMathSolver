//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_TEST_HPP
#define COMPUTATIONALMATHSOLVER_TEST_HPP
#include "../Interpolation/Newton.h"
#include "../Interpolation/Lagrange.h"
std::vector<double> generateData(int n) {
    std::vector<double> test(n);
    for (auto &element: test) {
        element = std::sin(rand()) * 1000;
    }
    return test;
}
void test(int n) {
    std::vector<double> x = generateData(10);
    std::vector<double> y = generateData(10);
    std::sort(x.begin(), x.end());
    std::sort(y.begin(), y.end());
    Lagrange lagrange(Template{x, y});
    Newton newton(Template{x, y});
    for (int i = 0; i < n; i++) {
        double t = std::sin(rand()) * 0.5 * (x.back() - x[0]) + 0.5 * (x.back() + x[0]);
        double l = lagrange.interpolate(t);
        double h = newton.interpolate(t);
        std::cerr << i << " " << l << " " << h << std::endl;
        assert(std::abs(l-h) <= 1e-8 && "Tb| pidor");
    }
}
#endif //COMPUTATIONALMATHSOLVER_TEST_HPP
