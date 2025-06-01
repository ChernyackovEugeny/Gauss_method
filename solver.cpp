#include "solver.hpp"
#include <cmath>

Eigen::VectorXd apply_gauss(Eigen::MatrixXd A, Eigen::VectorXd b) {
    int n = A.rows();
    for (int i = 0; i < n; ++i) {
        int pivot = i;
        for (int j = i + 1; j < n; ++j)
            if (std::abs(A(j, i)) > std::abs(A(pivot, i)))
                pivot = j;
        A.row(i).swap(A.row(pivot));
        std::swap(b(i), b(pivot));

        for (int j = i + 1; j < n; ++j) {
            double factor = A(j, i) / A(i, i);
            A.row(j) -= factor * A.row(i);
            b(j) -= factor * b(i);
        }
    }

    Eigen::VectorXd x(n);
    for (int i = n - 1; i >= 0; --i) {
        x(i) = (b(i) - A.row(i).segment(i + 1, n - i - 1).dot(x.segment(i + 1, n - i - 1))) / A(i, i);
    }
    return x;
}
