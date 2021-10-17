#include <iostream>
#include "Polynomial/Polynomial.hpp"
#include "Interpolation/Newton.h"
#include "Interpolation/Lagrange.h"
#include <cmath>
#include <algorithm>
#include <cassert>
#include "tests/test.hpp"
#include "Integration/Gauss.hpp"
double func(double x){
    return std::exp(-x*x);
}
int main() {
    std::map<int, double> poly;
    poly = {{0, 5},
            {1, -4},
            {2, 3},
            {3, 2},
            {4, 1}};
    Polynomial p(poly);
    std::cout << p << p.derivative(1);
    Template t = {{1, 2, 3, 4},
                  {1, 4, 9, 16}};
    Newton newton(t);
    std::cout << newton.interpolate(2.5) <<std::endl;
    test(5);
    Gauss<2> gauss(0, 1);
    std::cout << gauss.integrate(func);
    return 0;
}
