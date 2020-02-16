#include "matrix.hpp"

int main(int argc, char **argv)
{
    std::vector<std::vector<double> > mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};

    Matrix matObj(mat);
    // Matrix matObj2 = matObj.transpose();
    // matObj.transpose();
    std::cout << matObj.transpose() << std::endl;
    // std::cout << std::endl;
    std::cout << matObj << std::endl;

    return 0;
}