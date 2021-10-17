//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_GAUSSMEHTOD_HPP
#define COMPUTATIONALMATHSOLVER_GAUSSMEHTOD_HPP


#include <vector>
#include "DenseMatrix.hpp"
#include "../Utility/Consts.hpp"
#include "BackSubstitution.hpp"


int col_max(const DenseMatrix &A, const int &col);


unsigned int headTriangulation(DenseMatrix &A, std::vector<double> &b);


std::vector<double> headGaussMethod(DenseMatrix A, std::vector<double> b);


#endif //COMPUTATIONALMATHSOLVER_GAUSSMEHTOD_HPP
