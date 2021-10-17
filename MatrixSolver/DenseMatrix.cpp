//
// Created by d-qql on 17.10.2021.
//

#include "DenseMatrix.hpp"

DenseMatrix::DenseMatrix(const int &h, const int &w) : H(h), W(w) {
    matrix.resize(W * H);
}

DenseMatrix::DenseMatrix(const int &h, const int &w, const std::set<Triplet> &in) : H(h), W(w) {
    matrix.resize(W * H);
    for (auto i: in) {
        matrix[i.i * W + i.j] = i.value;
    }
}

double &DenseMatrix::operator()(const int &i, const int &j) {
    return matrix[i * W + j];
}

const double &DenseMatrix::operator()(const int &i, const int &j) const {
    return matrix[i * W + j];
}

const int &DenseMatrix::sizeH() const {
    return H;
}

const int &DenseMatrix::sizeW() const {
    return W;
}

void DenseMatrix::swap(const int &first, const int &second) {
    for (int j = 0; j < W; ++j) {
        std::swap(matrix[first * W + j], matrix[second * W + j]);
    }
}

std::vector<double> operator*(const DenseMatrix &A, const std::vector<double> &b) {
    std::vector<double> res(A.sizeH());
    double sum;
    for (size_t i = 0; i < A.sizeH(); ++i) {
        sum = 0;
        for (size_t j = 0; j < A.sizeW(); ++j) {
            sum += A(i, j) * b[j];
        }
        res[i] = sum;
    }
    return res;
}

std::ostream &operator<<(std::ostream &os, const DenseMatrix &A) {
    for (std::size_t i = 0; i < A.sizeH(); ++i) {
        for (std::size_t j = 0; j < A.sizeW(); ++j) {
            os << A(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

