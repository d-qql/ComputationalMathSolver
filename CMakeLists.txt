cmake_minimum_required(VERSION 3.20)
project(ComputationalMathSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(ComputationalMathSolver main.cpp Polynomial/Polynomial.cpp Polynomial/Polynomial.hpp Template/Template.hpp Derivation/UnderfinedCoefficientsMethod.cpp Derivation/UnderfinedCoefficientsMethod.hpp Interpolation/Newton.cpp Interpolation/Newton.hpp Interpolation/Lagrange.cpp Interpolation/Lagrange.hpp tests/test.hpp Integration/Gauss.hpp MatrixSolver/DenseMatrix.cpp MatrixSolver/DenseMatrix.hpp MatrixSolver/Triplet.hpp MatrixSolver/Triplet.cpp MatrixSolver/GaussMehtod.cpp MatrixSolver/GaussMehtod.hpp MatrixSolver/BackSubstitution.cpp MatrixSolver/BackSubstitution.hpp Utility/Consts.cpp Utility/Consts.hpp Utility/Overloads.cpp Utility/Overloads.hpp Integration/NewtonCotes.cpp Integration/NewtonCotes.hpp Interpolation/Chebyshev.cpp Interpolation/Chebyshev.hpp)
