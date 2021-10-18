
#include "Interpolation/Newton.hpp"
// реализуем функцию, которую необходимо заменить полиномом
double func(double x) {
    return std::exp(x)*sin(x);
}

int main() {
    // создаем интерполятор Ньютона, указав крайние точки отрезка(тут [-1, 1])
    // и необходимое число узлов, а также нашу функцию
    Newton newton(2, 4, 4, func);
    // выводим интерполяционный полином
    newton.get_polynomial();
    return 0;
}
