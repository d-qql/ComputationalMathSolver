//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_BACKSUBSTITUTION_HPP
#define COMPUTATIONALMATHSOLVER_BACKSUBSTITUTION_HPP

#include <cmath>
#include <iostream>
#include "DenseMatrix.hpp"
std::vector<double> backSubstTopTriangular(const DenseMatrix& A, const std::vector<double>& b);


std::vector<double> backSubstTopTriangular(const DenseMatrix& A, const std::vector<double>& b, size_t SZ);

std::vector<double> backSubstLowerTriangular(const DenseMatrix& A, const std::vector<double>& b);


#endif //COMPUTATIONALMATHSOLVER_BACKSUBSTITUTION_HPP
