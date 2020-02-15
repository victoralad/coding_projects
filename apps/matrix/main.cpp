#include "matrix.hpp"

int main(int argc, char **argv)
{
    int rows = 3, cols = 3;
    double mat[rows][cols] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Matrix matObj(rows, cols);
    matObj.matrix = mat;
    transpose(mat);
    std::cout << matrixObj << std::endl;

    return 0;
}