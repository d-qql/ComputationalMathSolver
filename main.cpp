
#include "Interpolation/Newton.hpp"

double func(double x) {
    return std::exp(-x * x);
}

int main() {

    Newton newton(-1, 1, 7, func);
    std::cout << newton.interpolate(0) << std::endl;
    return 0;
}
