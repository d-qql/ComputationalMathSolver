//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_OVERLOADS_HPP
#define COMPUTATIONALMATHSOLVER_OVERLOADS_HPP


#include <vector>
#include <iostream>
std::vector<double> operator*(const double& k, const std::vector<double>& b);

double operator*(const std::vector<double>& a, const std::vector<double>& b);

std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b);

std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b);

std::ostream& operator<<(std::ostream& os, const std::vector<double>& b);


#endif //COMPUTATIONALMATHSOLVER_OVERLOADS_HPP
