//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_NEWTONCOTES_HPP
#define COMPUTATIONALMATHSOLVER_NEWTONCOTES_HPP

#include <functional>
#include <vector>
#include <cmath>
#include <iostream>
class NewtonCotes {
public:
    double trapeze(const std::vector<double> &x, std::function<double(double)> function);
    double trapeze(double a, double b, int n, std::function<double(double)> function);

    double sympson(const std::vector<double> &x, std::function<double(double)> function);
    double sympson(double a, double b, int n, std::function<double(double)> function);

    double three_eights(const std::vector<double> &x, std::function<double(double)> function);
    double three_eights(double a, double b, int n, std::function<double(double)> function);



};


#endif //COMPUTATIONALMATHSOLVER_NEWTONCOTES_HPP
