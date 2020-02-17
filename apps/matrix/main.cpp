#include "matrix.hpp"

int main(int argc, char **argv)
{
    std::vector<std::vector<double> > mat1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12} };

    std::vector<std::vector<double> > mat2 = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

    Matrix matObj1(mat1);
    Matrix matObj2(mat2);

    // std::cout << matObj1 * matObj2 << std::endl;

    Matrix matObjA = matObj1 * matObj2;
    std::cout << matObj1 << std::endl;

    // Matrix matObj = matObj1;
    // std::cout << matObj1 << std::endl;

    return 0;
}