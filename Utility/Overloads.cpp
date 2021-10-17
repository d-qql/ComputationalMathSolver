//
// Created by d-qql on 17.10.2021.
//

#include "Overloads.hpp"
std::vector<double> operator*(const double& k, const std::vector<double>& b){
    std::vector<double> res(b.size());
    for(size_t i = 0; i < b.size(); ++i){
        res[i] = b[i] * k;
    }
    return res;
}
double operator*(const std::vector<double>& a, const std::vector<double>& b){
    double sum = 0;
    for(size_t i = 0; i < b.size(); ++i){
        sum += b[i] * a[i];
    }
    return sum;
}
std::vector<double> operator-(const std::vector<double>& a, const std::vector<double>& b){
    std::vector<double> res(a.size());
    for(size_t i = 0; i < a.size(); ++i){
        res[i] = a[i] - b[i];
    }
    return res;
}
std::vector<double> operator+(const std::vector<double>& a, const std::vector<double>& b){
    std::vector<double> res(a.size());
    for(size_t i = 0; i < a.size(); ++i){
        res[i] = a[i] + b[i];
    }
    return res;
}
std::ostream& operator<<(std::ostream& os, const std::vector<double>& b){
    os<<"\n";
    for(auto i : b){
        os<<i<<" ";
    }
    return os;
}