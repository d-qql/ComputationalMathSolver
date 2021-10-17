//
// Created by d-qql on 17.10.2021.
//

#include "GaussMehtod.hpp"
int col_max(const DenseMatrix &A, const int& col) {

    double max = std::abs(A(col,col));
    int maxPos = col;
    for (int i = col+1; i < A.sizeH(); ++i) {     //поиск максимального по модулю элемента в столбце col под диагональю
        double element = std::abs(A(i, col));
        if (element > max) {
            max = element;
            maxPos = i;
        }
    }
    return maxPos;
}
unsigned int headTriangulation(DenseMatrix &A, std::vector<double> &b) {


    unsigned int swapCount = 0;

    for (int i = 0; i < A.sizeH()-1; ++i) {
        int imax = col_max(A, i); //индекс максимального по модулю элемента под диагональю
        if(std::abs(A(imax, i)) < tolerance){  //если максимальный равен 0, то пропускаем столбец из рассмотрения
            continue;
        }else {
            if (i != imax) {
                A.swap(i, imax);        //переставляем строку с максимальным по модулю элементом с текущей местами
                std::swap(b[i], b[imax]); //элемент свободного столбца также переставляется
                ++swapCount;
            }

            for (int k = i + 1; k < A.sizeH(); ++k) { //проход по всем строкам под текущей
                double coef = (A(k, i) / A(i, i));
                for (int j = i; j < A.sizeW(); ++j) { //проход по всем элементам строки
                    A(k, j) -= A(i, j) * coef;          //вычитание из строки k строки i, умноженной на коэффициент для зануления элементов столбца i
                }
                b[k] -= b[i] * coef; //вычитание свободного члена уравнения
            }
        }
    }
    return swapCount;   //возвращаем число перестановок(может потребоваться для поиска определителя)
}

std::vector<double> headGaussMethod(DenseMatrix A,
                                    std::vector<double> b) {

    headTriangulation(A, b); //приводим матрицу к верхнетреугольной с выбором главного элемента
    return backSubstTopTriangular(A, b);
}