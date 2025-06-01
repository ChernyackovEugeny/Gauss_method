#include "solver.hpp"
#include "generator.hpp"
#include <gtest/gtest.h>

TEST(GaussSolverTest, SmallSystem) {
    Eigen::MatrixXd A(2, 2);
    A << 2, 1,
         5, 7;
    Eigen::VectorXd b(2);
    b << 11, 13;

    Eigen::VectorXd x = apply_gauss(A, b);
    Eigen::VectorXd expected(2);
    expected << 7.111111, -3.222222;

    ASSERT_TRUE((x - expected).norm() < 1e-4);
}

TEST(GaussSolverTest, LargeRandomSystem) {
    constexpr int size = 300;
    constexpr unsigned int seed = 123;

    auto [A, x_true] = generate(size, seed);
    Eigen::VectorXd b = A * x_true;

    Eigen::VectorXd x = apply_gauss(A, b);

    double residual = (A * x - b).norm();

    ASSERT_LT(residual, 1e-8);
}
