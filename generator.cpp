#include <Eigen/Dense>
#include <random>

std::pair<Eigen::MatrixXd, Eigen::VectorXd> generate(int n, unsigned int seed) {
    std::mt19937 gen(seed);
    std::uniform_real_distribution<> dist(-10.0, 10.0);

    Eigen::MatrixXd A(n, n);
    Eigen::VectorXd b(n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            A(i, j) = dist(gen);
        }
        b(i) = dist(gen);
    }

    return {A, b};
}
