//
// Created by d-qql on 17.10.2021.
//

#include "BackSubstitution.hpp"
std::vector<double> backSubstTopTriangular(const DenseMatrix& A, const std::vector<double>& b){
    std::vector<double> res(b.size());
    res.back() = b.back()/A(A.sizeH()-1, A.sizeW()-1);
    double sum;
    for(int i = b.size() - 2; i >= 0; --i){
        sum = 0;
        for(size_t j = i + 1; j < b.size(); ++j){
            sum += A(i, j) * res[j];
        }
        res[i] = (b[i] - sum) / A(i, i);
    }
    return res;
}
std::vector<double> backSubstTopTriangular(const DenseMatrix& A, const std::vector<double>& b, size_t SZ){
    std::vector<double> res(b.size()); //?
    res.back() = b.back()/A(SZ-1, SZ-1);
    double sum;
    for(int i = int(SZ) - 2; i >= 0; --i){
        sum = 0;
        for(size_t j = i + 1; j < b.size(); ++j){
            sum += A(i, j) * res[j];
        }
        res[i] = (b[i] - sum) / A(i, i);
    }
    return res;
}
std::vector<double> backSubstLowerTriangular(const DenseMatrix& A, const std::vector<double>& b){
    std::vector<double> res(b.size());
    res[0] = b[0]/A(0, 0);
    double sum;
    for(int i = 1; i < A.sizeH(); ++i){
        sum = 0;
        for(int j = 0; j < i; ++j){
            sum += A(i, j) * res[j];
        }
        res[i] = (b[i] - sum) / A(i, i);
    }
    return res;
}