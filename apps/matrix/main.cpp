#include "matrix.hpp"

int main(int argc, char **argv)
{
    std::vector<std::vector<double> > mat = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    Matrix matObj(mat);
    // matObj.transpose(mat);
    std::cout << matObj << std::endl;

    return 0;
}