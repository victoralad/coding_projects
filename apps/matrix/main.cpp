#include "matrix.hpp"

int main(int argc, char **argv)
{
    std::vector<std::vector<double> > mat1 = { {1, 2, 3}, 
                                               {4, 5, 6}, 
                                               {7, 8, 9}, 
                                               {3, 2, 1} };

    std::vector<std::vector<double> > mat2 = { {1, 2, 3, 4}, 
                                               {5, 6, 7, 8}, 
                                               {4, 3, 2, 1} };

    std::vector<std::vector<double> > mat3 = { {1, 2, 3, 4}, 
                                               {5, 6, 7, 8}, 
                                               {4, 3, 2, 1}, 
                                               {8, 7, 6, 5} };                                           

    Matrix matObj1(mat1);
    Matrix matObj2(mat2);
    Matrix matObj3(mat3);

    // std::cout << matObj1 * matObj2 << std::endl;

    Matrix matObjA = matObj1 * matObj2; // * matObj3;
    std::cout << matObjA << std::endl;

    // Matrix matObjC = matObj1;
    // std::cout << matObjC << std::endl;

    // int numthreads = std::thread::hardware_concurrency() ;
    // std::cout << numthreads << std::endl;

    return 0;
}