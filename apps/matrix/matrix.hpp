#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <omp.h>
#include <iomanip>
#include <memory>

/*
Author: Victor Aladele
Description:
 Implementing matrix class for matrix multiplication and transpose operations
*/

class Matrix
{
public:
    Matrix();                     
    Matrix(const Matrix &matrixObj); 
    Matrix(std::vector<std::vector<double> > &matrixIn);
    ~Matrix();                          // destructor
    std::vector<std::vector<double> >& transpose();             // transpose matrix
    std::vector<std::vector<double> >& operator*(const Matrix &matObj2);              // multiply two matrices together  matObj and matObj
    
    Matrix& operator=(const Matrix &matrixObj); // assign matrix to another matrix
    Matrix& operator=(std::vector<std::vector<double> >& newMatrix);
    // friend std::vector<std::vector<double> >& operator*(std::vector<std::vector<double> >& tempMatrix, const Matrix &matObj3);  // multiply two matrices together  vector and matObj
    friend std::ostream& operator<<(std::ostream &osstream, const Matrix &matrixObj); // print out matrix by overloading the << operator
    friend std::ostream& operator<<(std::ostream& oss, std::vector<std::vector<double> >& newMatrix);

private:
    std::vector<std::vector<double> > matrix;
    std::vector<std::vector<double> > newMatrix;
};

// default contructor
inline Matrix::Matrix() : nRows(0), nCols(0)
{
}

// constructor with arguments
inline Matrix::Matrix(std::vector<std::vector<double> > &matrixIn) : matrix(matrixIn)
{
}

// copy constructor
inline Matrix::Matrix(const Matrix &matrixObj)
{
    matrix.resize(matrixObj.matrix.size());
    int i, j;
    #pragma omp parallel for private(i, j)
    for (i = 0; i < nRows; ++i)
    {
        matrix[i].resize(nCols);
        for (j = 0; j < nCols; ++j)
        {
            // Copy over everything
            matrix[i][j] = matrixObj.matrix[i][j];
        }
    }
}

inline Matrix::~Matrix()
{
}

// transpose matrix
inline std::vector<std::vector<double> >& Matrix::transpose()
{
    newMatrix.resize(nCols);
    int i, j;
    #pragma omp parallel for private(i, j)
    for (j = 0; j < nCols; ++j)
    {
        newMatrix[j].resize(nRows);
        for (i = 0; i < nRows; ++i)
        {
            newMatrix[j][i] = matrix[i][j];
        }
    }
    return newMatrix;
}

// multiply two matrices matObj1 and matObj2
inline std::vector<std::vector<double> >& Matrix::operator*(const Matrix &matObj2) 
{
    if (nCols != matObj2.nRows)
    {
        std::cout << "Matrix dimensions do not allow for multiplication" << std::endl;
        newMatrix.resize(1); // initialize newMatrix before returning it
        return newMatrix;
    }
    
    newMatrix.resize(nRows);
    int i, j, k;
    #pragma omp parallel for private(i, j, k)
    for (i = 0; i < nRows; ++i)
    {
        newMatrix[i].resize(matObj2.nCols);
        for (j = 0; j < matObj2.nCols; ++j)
        {
            for (k = 0; k < matObj2.nRows; ++k)
            {
                //calculates the dot product of the rows of matrix1 with the corresponding
                //columns of matrix2
                newMatrix[i][j] += matrix[i][k] * matObj2.matrix[k][j]; 
            }
        }
    }
    std::cout << "hey" << std::endl;

    return newMatrix;
}

// inline std::vector<std::vector<double> > operator*(std::vector<std::vector<double> >& tempMatrix, const Matrix &matObj3)
// {
//     Matrix tempMatObj(tempMatrix);
//     tempMatObj = matObj3.transpose() * tempMatObj.transpose();
//     tempMatObj = tempMatObj.transpose();
//     return tempMatObj.matrix;
// }

// assign matrix to another matrix
inline Matrix& Matrix::operator=(const Matrix &matrixObj)
{
    // Check to see if we are trying to assign ourself
    if (this == &matrixObj)
    {
       return *this;
    }
    nRows = matrixObj.nRows;
    nCols = matrixObj.nCols;
    int i, j;
    #pragma omp parallel for private(i, j)
    for (i = 0; i < nRows; i++)
    {
        for (j = 0; j < nCols; j++)
        {
            // Copy over everything
            matrix[i][j] = matrixObj.matrix[i][j];
        }
    }
    // Return
    return *this;
}

// assign matrix to another matrix
inline Matrix& Matrix::operator=(std::vector<std::vector<double> >& newMatrix)
{
    std::cout << "yo" << std::endl;
    nRows = newMatrix.size();
    nCols = newMatrix[0].size();
    matrix.resize(nRows);
    int i, j;
    // #pragma omp parallel for private(i, j)
    for (i = 0; i < nRows; i++)
    {
        matrix[i].resize(nCols);
        for (j = 0; j < nCols; j++)
        {
            // Copy over everything
            matrix[i][j] = newMatrix[i][j];
        }
    }
    // Return
    return *this;
}

// print out matrix by overloading the << operator
inline std::ostream& operator<<(std::ostream& oss, const Matrix &matrixObj)
{
    int i, j;
    // #pragma omp parallel for private(i, j)
    for (i = 0; i < matrixObj.nRows; i++)
    {
        for (j = 0; j < matrixObj.nCols; j++)
        {
            oss << std::scientific << std::setw(12) << std::setprecision(3) << matrixObj.matrix[i][j]; // add the matrix to oss in the right format
        }
        oss << std::endl;
    }
    return oss;
}

// print out matrix by overloading the << operator
inline std::ostream& operator<<(std::ostream& oss, std::vector<std::vector<double> >& newMatrix)
{
    int i, j;
    // #pragma omp parallel for private(i, j)
    for (i = 0; i < newMatrix.size(); ++i)
    {
        for (j = 0; j < newMatrix[i].size(); ++j)
        {
            oss << std::scientific << std::setw(12) << std::setprecision(3) << newMatrix[i][j]; // add the matrix to oss in the right format
        }
        oss << std::endl;
    }
    return oss;
}

#endif 

