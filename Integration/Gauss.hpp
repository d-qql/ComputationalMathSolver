//
// Created by d-qql on 17.10.2021.
//

#ifndef COMPUTATIONALMATHSOLVER_GAUSS_HPP
#define COMPUTATIONALMATHSOLVER_GAUSS_HPP

#include <array>
#include <vector>
#include <functional>

/**
 *
 * @tparam N Число у
 */
template<int N>
class Gauss {
private:
    double a;
    double b;
    const std::array<std::vector<std::pair<double, double>>, 6> roots_weights = {
            {{{0, 2}},
             {{-0.5773503, 1}, {0.5773503, 1}},
             {{-0.7745967, 0.5555556}, {0, 0.8888889}, {0.7745967, 0.5555556}},
             {{-0.8611363, 0.3478548}, {-0.3399810, 0.6521451}, {0.3399810, 0.6521451}, {0.8611363, 0.3478548}},
             {{-0.9061798, 0.4786287}, {-0.5384693, 0.2369269}, {0, 0.5688888}, {0.5384693, 0.2369269},
              {0.9061798, 0.4786287}},
             {{-0.9324700, 0.1713245}, {-0.6612094, 0.3607616}, {-0.2386142, 0.4679140}, {0.2386142, 0.4679140},
              {0.6612094, 0.3607616}, {0.9324700, 0.1713245}}}};
    std::vector<std::pair<double, double>> movedRoots_weights;
public:
    Gauss(double a, double b);

    double integrate(std::function<double(double)> function);
};

template<int N>
Gauss<N>::Gauss(double a, double b): a(a), b(b){
    for (auto i: roots_weights[N - 1]) {
        movedRoots_weights.push_back({(a + b) / 2. + (b - a) / 2. * i.first, i.second});
    }
}

template<int N>
double Gauss<N>::integrate(std::function<double(double)> function) {
    double result = 0;
    for (auto i: movedRoots_weights) {
        result += i.second * function(i.first);
    }
    return (b - a) / 2. * result;
}


#endif //COMPUTATIONALMATHSOLVER_GAUSS_HPP
