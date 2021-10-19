//https://github.com/d-qql/ComputationalMathSolver/tree/task_2
#include "Integration/Gauss.hpp"

double func(double x) {
    return x * x * x + 5 * x * x + 10 * x + 4.5;
}

int main() {

    Gauss<3> gauss(-3, 1);
    std::cout << "Значение интеграла: " << gauss.integrate(func) << std::endl;
    std::cout << "Квадратура точна для полинома степени не выше 5, данный полином третьей степени.";

    return 0;
}
