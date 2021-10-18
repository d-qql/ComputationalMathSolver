//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_TRIPLET_HPP
#define COMPUTATIONALMATHSOLVER_TRIPLET_HPP
#include <cmath>
#include <iostream>
struct Triplet {
    int i;
    int j;
    double value;

    bool operator<(Triplet const &rgh) const;
};
#endif //COMPUTATIONALMATHSOLVER_TRIPLET_HPP
