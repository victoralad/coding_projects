#include "matrix.hpp"
#include <fstream>
#include <chrono>

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
    Matrix matObj;

    // std::cout << matObj1.transpose() << std::endl;
    // matObj = matObj1.transpose();
    // std::cout << matObj << std::endl;

    // //------------ Test to check that multiplication with matrices of the wrong dimensions are not allowed -------------
    // std::cout << matObj1 * matObj3 << std::endl;     

    // std::cout << matObj1 * matObj2 << std::endl;
    // matObj = matObj1 * matObj2;
    // std::cout << matObj << std::endl;

    // std::cout << matObj1 * matObj2 * matObj3 << std::endl;
    // matObj = matObj1 * matObj2 * matObj3;
    // std::cout << matObj << std::endl;

    // // check to see that all the operations above have not affected the values of the original matrices
    // std::cout << matObj1 << "\n" << matObj2 << "\n" << matObj3 << std::endl;


    // // ------------ The code below is used to evaluate the performance and correctness of the multihreaded part of the program --------
    int nRows, nCols;

    std::ifstream data_matrix;
    data_matrix.open("Test1000.txt");

    data_matrix >> nRows >> nCols;

    std::vector <std::vector<double> > matrix(nRows, std::vector<double>(nCols, 0));
    for (int i = 0; i < nRows; ++i)
    {
        for (int j = 0; j < nCols; ++j)
        {
            data_matrix >> matrix[i][j];
        }
    }
    data_matrix.close();

    Matrix matObjTest(matrix);

    auto start = std::chrono::system_clock::now();

    Matrix matObjTest2 = matObjTest.transpose();
    std::cout << matObjTest << std::endl;

    auto end = std::chrono::system_clock::now();

    auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(end - start);  // elasped time in seconds
    std::cout << elapsed.count() << '\n'; 

    return 0;
}