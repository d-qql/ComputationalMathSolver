//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_UNDERFINEDCOEFFICIENTSMETHOD_HPP
#define COMPUTATIONALMATHSOLVER_UNDERFINEDCOEFFICIENTSMETHOD_HPP


#include "../Template/Template.hpp"
#include "../MatrixSolver/GaussMehtod.hpp"
#include <cmath>
#include <iostream>

class UnderfinedCoefficientsMethod {
private:
    std::vector<double> x;
    std::vector<double> y;
    double h;
public:
    UnderfinedCoefficientsMethod(const Template &aTemplate);
    /***
     * Вычислить производную
     * @param j номер узла, в котором необходимо вычислить производную в отсчете с 0
     * @param n порядок производной
     * @return численное значение производной
     */
    double calculate(int j, int n = 1) const;
};


#endif //COMPUTATIONALMATHSOLVER_UNDERFINEDCOEFFICIENTSMETHOD_HPP
