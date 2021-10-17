cmake_minimum_required(VERSION 3.20)
project(ComputationalMathSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComputationalMathSolver main.cpp Polynomial/Polynomial.cpp Polynomial/Polynomial.hpp Template/Template.hpp Derivation/UnderfinedCoefficientsMethod.cpp Derivation/UnderfinedCoefficientsMethod.hpp Interpolation/Newton.cpp Interpolation/Newton.h Interpolation/Lagrange.cpp Interpolation/Lagrange.h tests/test.hpp Integration/Gauss.hpp)
