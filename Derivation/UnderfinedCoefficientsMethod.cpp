//
// Created by d-qql on 17.10.2021.
//

#include "UnderfinedCoefficientsMethod.hpp"
#include "../MatrixSolver/GaussMehtod.hpp"

UnderfinedCoefficientsMethod::UnderfinedCoefficientsMethod(const Template &aTemplate) : x(aTemplate.x), y(aTemplate.y) {
    h = x[1] - x[0];
    for (int i = 2; i < x.size(); ++i) {
        double h1 = x[i] - x[i - 1];
        if (std::abs(h - h1) > 1e-5) {
            std::cerr << "НЕРАВНОМЕРНЫЙ ШАГ СЕТКИ В МЕТОДЕ НЕОПРЕДЕЛЕННЫХ КОЭФФИЦИЕНТОВ!!!" << std::endl
                      << "Дальнейшее вычисление может быть неверно" << std::endl;
        }
    }
}

double UnderfinedCoefficientsMethod::calculate(int j, int n) const {
    int l = j;
    int m = x.size() - j - 1;
    Triplet curr_elem;
    std::set<Triplet> in;

    // generate matrix
    for (int k = 0; k < x.size(); ++k) {
        for (int s = 0; s < x.size(); ++s) {
            curr_elem = {k, s, std::pow(-l + s, k)};
            in.insert(curr_elem);
        }
    }
    DenseMatrix A(x.size(), x.size(), in);

    //solve system
    std::vector<double> b(x.size(), 0);
    b[n] = 1;
    std::vector<double> alpha = headGaussMethod(A, b);

    // calculate derivative
    double result = 0;
    for(int i = 0; i < x.size(); ++i){
        result += alpha[i] * y[i];
    }
    return result;
}
