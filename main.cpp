// https://github.com/d-qql/ComputationalMathSolver
#include "Interpolation/Newton.hpp"
// реализуем функцию, которую необходимо заменить полиномом
double func(double x) {
    return sin(x);
}

int main() {
    // создаем интерполятор Ньютона, указав крайние точки отрезка(тут [-1, 1])
    // и необходимое число узлов, а также нашу функцию
    Newton newton(0, 5, 3, func);
    // выводим интерполяционный полином
    newton.get_polynomial();
    std::cout << "Константа Лебега ~ 2/Pi * ln(2) => Ошибка <= sup(|deltaF|) * L = 2 * 2/Pi * ln(2)";
    return 0;
}
