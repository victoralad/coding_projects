#include "matrix.hpp"
#include <fstream>
#include <chrono>

int main(int argc, char **argv)
{
    // int nRows, nCols;
    // std::ifstream data_matrix;
    // data_matrix.open("Test1000.txt");
    // data_matrix >> nRows >> nCols;
    // std::vector <std::vector<double> > matrix(nRows, std::vector<double>(nCols, 0));
    // for (long long i = 0; i < nRows; i++)
    // {
    //     for (long long j = 0; j < nCols; j++)
    //     {
    //         data_matrix >> matrix[i][j];
    //     }
    // }
    // data_matrix.close();
    // Matrix matObjTest(matrix);
    // auto start = std::chrono::system_clock::now();

    // Matrix matObjTest2 = matObjTest;
    // // std::cout << matObjTest2 << std::endl;

    // auto end = std::chrono::system_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    // std::cout << elapsed.count() << '\n';
    



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
    Matrix matObj;

    std::cout << matObj1.transpose() << std::endl;
    matObj = matObj1.transpose();
    std::cout << matObj << std::endl;

    // std::cout << matObj1 * matObj2 << std::endl;
    // matObj = matObj1 * matObj2;
    // std::cout << matObj << std::endl;

    // std::cout << matObj1 * matObj2 * matObj3 << std::endl;
    // matObj = matObj1 * matObj2 * matObj3;
    // std::cout << matObj << std::endl;

    // // check to see that all the operations above have not affected the values of the original matrices
    std::cout << matObj1 << "\n" << matObj2 << "\n" << matObj3 << std::endl;

    return 0;
}