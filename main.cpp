#include "solver.hpp"
#include "work_csv.hpp"
#include "generator.hpp"
#include <iostream>
#include <string>

int main() {
    std::string input_file;
    std::string output_file;
    
    std::cout << "Enter the name of csv file: ";
    std::getline(std::cin, input_file);
    std::cout << "Enter output CSV file name: ";
    std::getline(std::cin, output_file);

    try {
        auto [A, b] = read_csv(input_file);
        Eigen::VectorXd x = apply_gauss(A, b);
        write_csv(output_file, x);
        std::cout << "Solution written to " << output_file << "\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
