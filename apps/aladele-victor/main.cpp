#include "aladele-victor.hpp"

int main(int argc, char **argv)
{
    // Initialize vectors for matrix interface
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

    // Initialize objects
    Matrix matObj1(mat1);
    Matrix matObj2(mat2);
    Matrix matObj3(mat3);
    Matrix matObj;
    
    // //---------- Test to check that transpose function works correctly -------------
    std::cout << "------------- Test transpose function --------------\n\n";
    std::cout << matObj1.transpose() << std::endl;
    matObj = matObj1.transpose();
    std::cout << matObj << std::endl;     

    // //--------- Test to check that the multiplication subroutine works correctly -------------
    std::cout << "------------- Test multiplication subroutine --------------\n\n";
    std::cout << matObj1 * matObj2 << std::endl;
    matObj = matObj1 * matObj2;
    std::cout << matObj << std::endl;

    // //--------- Test to check that multiple matrices can be multiplied together all at once (an advantage of overloading the operator '*') ----------
    std::cout << "------------- Test multiplication of more than two matrices at once ------------\n\n";
    std::cout << matObj1 * matObj2 * matObj3 << std::endl;
    matObj = matObj1 * matObj2 * matObj3;
    std::cout << matObj << std::endl;

    // //------------ Test to check that multiplication with matrices of the wrong dimensions are not allowed -------------
    std::cout << "------------- Test to see that matrix multiplication with wrong dimensions are not allowed ------------\n\n";
    std::cout << matObj1 * matObj3 << std::endl;

    // //----------- check to see that all the operations above have not affected the values of the original matrices ---------
    std::cout << "------------- Test to see if original matrices values were preserved -------------\n\n";
    std::cout << matObj1 << "\n" << matObj2 << "\n" << matObj3 << std::endl;

    return 0;
}