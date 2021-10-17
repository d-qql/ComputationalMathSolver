//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_DENSEMATRIX_HPP
#define COMPUTATIONALMATHSOLVER_DENSEMATRIX_HPP

#include <vector>
#include "Triplet.hpp"
#include "set"
#include <iostream>

class DenseMatrix{

private:

    std::vector<double> matrix;
    int H, W;

public:
    DenseMatrix(const int &h, const int& w);

    DenseMatrix(const int &h, const int& w, const std::set<Triplet>& in);

    double& operator()(const int& i, const int& j);
    const double& operator()(const int& i, const int& j) const;
    [[nodiscard]] const int& sizeH() const;
    [[nodiscard]] const int& sizeW() const;
    void swap(const int& first, const int& second);
};


std::vector<double> operator*(const DenseMatrix& A, const std::vector<double>& b);

std::ostream& operator<<(std::ostream& os, const DenseMatrix& A);



#endif //COMPUTATIONALMATHSOLVER_DENSEMATRIX_HPP
