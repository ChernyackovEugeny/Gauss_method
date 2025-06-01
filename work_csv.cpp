#include <eigen3/Eigen/Dense>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::pair<Eigen::MatrixXd, Eigen::VectorXd> read_csv(std::string& path) {
    std::ifstream input(path);
    std::vector<std::vector<double>> data;
    std::string line;

    while (std::getline(input, line)) {
        std::stringstream str(line);
        std::string cell;
        std::vector<double> row;
        
        while (std::getline(str, cell, ',')) {
            row.push_back(std::stod(cell));
        }
        data.push_back(row);
    }

    int rows = data.size();
    int cols = data[0].size();
    
    Eigen::MatrixXd A(rows, cols - 1);
    Eigen::VectorXd b(rows);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols - 1; ++j) {
            A(i, j) = data[i][j];
        }
        b(i) = data[i][cols - 1];
    }
    return {A, b};
}

void write_csv(std::string& path, Eigen::VectorXd& a) {
    std::ofstream output(path);
    
    for (int i = 0; i < a.size(); ++i) {
        output << a(i);
        if (i < a.size() - 1) output << ",";
    }
    output << "\n";
}
