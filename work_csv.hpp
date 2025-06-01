#ifndef WORKCSV
#define WORKCSV
#include <eigen3/Eigen/Dense>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::pair<Eigen::MatrixXd, Eigen::VectorXd> read_csv(std::string& path);

void write_csv(std::string& path, Eigen::VectorXd& a);

#endif
