//
// Created by d-qql on 17.10.2021.
//
#include "Triplet.hpp"

bool Triplet::operator<(const Triplet &rgh) const {
    return this->i < rgh.i || (this->i == rgh.i && this->j < rgh.j);
}
