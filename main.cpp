#include <iostream>
#include "Polynomial/Polynomial.hpp"
#include "Interpolation/Newton.hpp"
#include "Interpolation/Lagrange.hpp"
#include <cmath>
#include <algorithm>
#include <cassert>
#include "tests/test.hpp"
#include "Integration/Gauss.hpp"
#include "MatrixSolver/GaussMehtod.hpp"
#include "Derivation/UnderfinedCoefficientsMethod.hpp"
#include "Integration/NewtonCotes.hpp"

double func(double x) {
    return std::exp(-x * x);
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
    NewtonCotes newtonCotes;
    std::vector<double> x = {1, 2, 3, 4, 5};
    std::cout << newtonCotes.trapeze(x, func) << " " << newtonCotes.trapeze(1, 5, 4, func) << " "
              << newtonCotes.sympson(x, func) << " " << newtonCotes.sympson(1, 5, 4, func) << " "
              << newtonCotes.three_eights(x, func) << " " << newtonCotes.three_eights(1, 5, 4, func) << std::endl;
    std::cout << gauss.integrate(func) << std::endl;
    Template deriv = {{1,   2,    3},
                      {0.5, 0.25, 0.25}};
    UnderfinedCoefficientsMethod UCM(deriv);
    std::cout << UCM.calculate(2);
    return 0;
}
