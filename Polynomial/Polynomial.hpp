//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_POLYNOMIAL_HPP
#define COMPUTATIONALMATHSOLVER_POLYNOMIAL_HPP

#include <map>
#include <iostream>
class Polynomial {
private:
    std::map<int, double> coefs;
public:
    Polynomial();
    Polynomial(const std::map<int, double>& coefs);
    Polynomial derivative(int n = 1);
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);

};
std::ostream& operator<<(std::ostream& os, const Polynomial& polynomial);


#endif //COMPUTATIONALMATHSOLVER_POLYNOMIAL_HPP
