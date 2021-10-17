//
// Created by d-qql on 17.10.2021.
//

#include "Polynomial.hpp"

Polynomial::Polynomial(const std::map<int, double> &coefs) : coefs(coefs) {

}

Polynomial Polynomial::derivative(int n) {
    Polynomial result = *this;
    std::pair<int, double> temp;
    for (int i = 0; i < n; ++i) {
        for (std::map<int, double>::iterator it = result.coefs.begin(); it != result.coefs.end();) {
            if (it->first >= 1) {
                temp = {it->first - 1, it->second * it->first};
                result.coefs.insert(temp);
                it = result.coefs.erase(it);
            } else {
                it = result.coefs.erase(it);
            }
        }
    }
    return result;
}

Polynomial::Polynomial() {

}

std::ostream &operator<<(std::ostream &os, const Polynomial &polynomial) {
    if(polynomial.coefs.size() == 0){
        os << 0 << std::endl;
        return os;
    }
    for (auto elm = polynomial.coefs.rbegin(); elm != polynomial.coefs.rend(); ++elm) {
        os.setf(std::ios::showpos);
        os << elm->second;
        os.unsetf(std::ios::showpos);
        os << "*x^" << elm->first << " ";
    }
    os << std::endl;
    return os;
}


