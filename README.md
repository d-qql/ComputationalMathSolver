# ComputationalMathSolver
# Решалка твоей контрольной по вычматам
## 1. Численное дифференцирование методом неопределенных коэффициентов
Найти первую производную функции, заданной шаблоном в точке x = 3
|x|1|2|3|
|-|-|-|-|
|y|0.5|0.25|0.25|
### main.cpp:
```cpp
#include "Derivation/UnderfinedCoefficientsMethod.hpp"

int main() {
    // создаем шаблон
    Template our_template = {
                      {1,   2,    3},
                      {0.5, 0.25, 0.25}
                      };
    // создаем экземпляр класса метода неопределенных коэффициентов, послав шаблон аргументом.
    UnderfinedCoefficientsMethod UCM(our_template);
    // вычисляем значение производной с помощью метода calculate, послав аргументом порядковый номер 
    // точки шаблона(начиная с нуля), в которой необходимо найти производную
    std::cout << UCM.calculate(2);
    return 0;
}
```
Если необходимо найти производную более высокого порядка (к примеру 3-ю), необходимо послать 
порядок производной вторым аргументом:
```cpp
UCM.calculate(2, 3);
```
## 2. Интерполяция
Интерполировать значение функции, заданной шаблоном в точке x = 2.5

|x|1|2|3|4|
|-|-|-|-|-|
|y|1|4|9|16|

### main.cpp:
```cpp
#include "Interpolation/Newton.hpp"

int main() {
    // создаем шаблон
    Template t = {
                  {1, 2, 3, 4},
                  {1, 4, 9, 16}
                  };
    // создаем экземпляр интерполятора Ньютона
    Newton newton(t);
    // вызываем метод интерполяции в нужной точке
    std::cout << newton.interpolate(2.5) <<std::endl;
    return 0;
}
```
Аналогично можно использовать метод Лагранжа, вместо Ньютона(идентичны):
### main.cpp:
```cpp
#include "Interpolation/Lagrange.hpp"

int main() {
    // создаем шаблон
    Template t = {
                  {1, 2, 3, 4},
                  {1, 4, 9, 16}
                  };
    // создаем экземпляр интерполятора Лагранжа
    Lagrange lagrange(t);
    // вызываем метод интерполяции в нужной точке
    std::cout << lagrange.interpolate(2.5) <<std::endl;
    return 0;
}
```
## 3. Интегрирование
### Квадратура Гаусса
Построить квадратуру Гаусса на 2х узлах и вычислить интеграл ![изображение](https://user-images.githubusercontent.com/58688832/137779086-6ad56dd0-6797-4419-97bf-10dd78e8a452.png) :

#### main.cpp:
```cpp
#include "Integration/Gauss.hpp"

// Реализуем функцию, которую необходимо проинтегрировать
double func(double x) {
    return std::exp(-x * x);
}

int main() {
    // Создаем квадратуру Гаусса. Аргумент в <> - число узлов, аргументы конструктора - отрезок интегрирования(в данном случае от 0 до 1)
    Gauss<2> gauss(0, 1);
    // Расчитываем интеграл созданной нами функции
    std::cout << gauss.integrate(func) << std::endl;

    return 0;
}
```

### Методы Ньюона-Котеса
Вычислить интеграл ![изображение](https://user-images.githubusercontent.com/58688832/137779086-6ad56dd0-6797-4419-97bf-10dd78e8a452.png) :

#### Вариант 1:
#### main.cpp:

```cpp
#include "Integration/NewtonCotes.hpp"

// Реализуем функцию, которую необходимо проинтегрировать
double func(double x) {
    return std::exp(-x * x);
}

int main() {
    // Сами разобъем отрезок интегрирования с нужным нам шагом и запишем точки в вектор:
    std::vector<double> x = {0, 0.2, 0.4, 0.6, 0.6, 0.8, 1};
    NewtonCotes newtonCotes;
    // Вызовем один из возможных методов интегрирования (Трапеции, Симпсона, правило 3/8),
    // первый аргумент - разбиение отрезка интегрирования, второй - интегрируемая функция:
    std::cout << newtonCotes.trapeze(x, func) << " "
              << newtonCotes.sympson(x, func) << " "
              << newtonCotes.three_eights(x, func) << std::endl;

    return 0;
}
```
#### Вариант 2:
#### main.cpp:

```cpp
#include "Integration/NewtonCotes.hpp"

// Реализуем функцию, которую необходимо проинтегрировать
double func(double x) {
    return std::exp(-x * x);
}

int main() {
    double a = 0; // укажем нижнюю границу интегрирования
    double b = 1; // укажем верхнюю границу интегрирования
    int n = 6; // укажем число отрезков, на которое хотим разбить исходный отрезок интегрирования 
    NewtonCotes newtonCotes;
    // Вызовем один из возможных методов интегрирования (Трапеции, Симпсона, правило 3/8),
    // первый аргумент - нижняя граница, второй - верхняя граница, третий - число отрезков, четвертый - интегрируемая функция:
    std::cout << newtonCotes.trapeze(a, b, n, func) << " "
              << newtonCotes.sympson(a, b, n, func) << " "
              << newtonCotes.three_eights(a, b, n, func) << std::endl;

    return 0;
}
```
