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
    Matrix(std::vector<std::vector<double> > &matrixIn);
    ~Matrix();
    Matrix transpose() const;
    Matrix operator*(const Matrix &matObj2) const; 
    friend std::ostream& operator<<(std::ostream &osstream, const Matrix &matrixObj);

private:
    int nRows;
    int nCols;
    std::vector<std::vector<double> > matrix;
};

// default contructor
inline Matrix::Matrix() : nRows(0), nCols(0)
{
}

// constructor with arguments
inline Matrix::Matrix(std::vector<std::vector<double> > &matrixIn) : matrix(matrixIn), nRows(matrixIn.size()), nCols(matrixIn[0].size())
{
}

// destructor
inline Matrix::~Matrix()
{
}

// transpose matrix
inline Matrix Matrix::transpose() const
{
    Matrix tempMatObj;
    tempMatObj.nRows = nCols;
    tempMatObj.nCols = nRows;
    tempMatObj.matrix.resize(nCols);

    int i, j;
    #pragma omp parallel for private(i, j)  // Multi-threading command to ensure thread safety 
    for (j = 0; j < nCols; ++j)
    {
        tempMatObj.matrix[j].resize(nRows);
        for (i = 0; i < nRows; ++i)
        {
            tempMatObj.matrix[j][i] = matrix[i][j];
        }
    }

    return tempMatObj;
}

// multiply two matrices together
inline Matrix Matrix::operator*(const Matrix &matObj2) const
{
    Matrix tempMatObj;

    // Check to see that the dimensions of the matrices are appropriate for multiplication
    if (nCols != matObj2.nRows)
    {
        std::cout << "Matrix dimensions do not allow for multiplication" << std::endl;
        return tempMatObj;
    }
    
    tempMatObj.nRows = nRows;
    tempMatObj.nCols = matObj2.nCols;
    tempMatObj.matrix.resize(nRows);

    int i, j, k;
    #pragma omp parallel for private(i, j, k)   // Multi-threading command to ensure thread safety 
    for (i = 0; i < nRows; ++i)
    {
        tempMatObj.matrix[i].resize(matObj2.nCols);
        for (j = 0; j < matObj2.nCols; ++j)
        {
            for (k = 0; k < matObj2.nRows; ++k)
            {
                //calculates the dot product of the rows of matrix1 with the corresponding
                //columns of matrix2
                tempMatObj.matrix[i][j] += matrix[i][k] * matObj2.matrix[k][j]; 
            }
        }
    }

    return tempMatObj;
}

// print out matrix
inline std::ostream& operator<<(std::ostream& oss, const Matrix &matrixObj)
{
    for (int i = 0; i < matrixObj.nRows; ++i)
    {
        for (int j = 0; j < matrixObj.nCols; ++j)
        {
            oss << std::scientific << std::setw(12) << std::setprecision(3) << matrixObj.matrix[i][j]; // add the matrix to oss in the right format
        }
        oss << std::endl;
    }

    return oss;
}

#endif 