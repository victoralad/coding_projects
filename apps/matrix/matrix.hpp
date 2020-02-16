#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <thread>
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
    Matrix();                           // constructor
    Matrix(const Matrix &matrixObj);    // copy constructor
    Matrix(std::vector<std::vector<double> > &matrixIn);    // constructor with arguments
    ~Matrix();                          // destructor
    Matrix& transpose();             // transpose matrix
    Matrix& operator=(const Matrix &matrixObj); // assign matrix to another matrix
    friend Matrix operator*(const Matrix &matObj1, const Matrix &matObj2);              // multiply two matrices together
    friend std::ostream& operator<<(std::ostream &osstream, const Matrix &matrixObj); // print out matrix by overloading the << operator
    

private:
    int nRows;
    int nCols;
    // Matrix newMatrixObj;
    std::unique_ptr<Matrix> newMatObjPtr;
    std::vector<std::vector<double> > matrix;
};

// default contructor
inline Matrix::Matrix() : nRows(0), nCols(0), newMatObjPtr(new Matrix) 
{
}

// constructor with arguments
inline Matrix::Matrix(std::vector<std::vector<double> > &matrixIn) : matrix(matrixIn), nRows(matrixIn.size()), nCols(matrixIn[0].size())
{
}

// copy constructor
inline Matrix::Matrix(const Matrix &matrixObj)
{
    nRows = matrixObj.nRows;
    nCols = matrixObj.nCols;
    matrix.resize(nRows);
    for (int i = 0; i < nRows; ++i)
    {
        matrix[i].resize(nCols);
        for (int j = 0; j < nCols; ++j)
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
inline Matrix& Matrix::transpose()
{
    Matrix newMatObj(*this);
    std::cout << *this << std::endl;
    newMatObj.nRows = nRows;
    newMatObj.nCols = nCols;
    // add stuff here with multi-threading
    
    newMatObj.matrix.resize(nCols);
    for (int j = 0; j < nCols; ++j)
    {
        newMatObj.matrix[j].resize(nRows);
        for (int i = 0; i < nRows; ++i)
        {
            newMatObj.matrix[i][j] = matrix[i][j];
            // std::cout << newMatObj.matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return *this;
}

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
    for (int i = 0; i < nRows; i++)
    {
        for (int j = 0; j < nCols; j++)
        {
            // Copy over everything
            matrix[i][j] = matrixObj.matrix[i][j];
        }
    }
    // Return
    return *this;
}

// multiply two matricesmatObj1 and matObj2
inline Matrix operator*(const Matrix &matObj1, const Matrix &matObj2) 
{
    // Matrix newMatrix(matrixObj1.nRows, matObj2.nCols);
    Matrix newMatObj;
    newMatObj.nRows = matObj1.nRows;
    newMatObj.nCols = matObj2.nCols;

    newMatObj.matrix.resize(newMatObj.nRows);
    for (int i = 0; i < newMatObj.nRows; ++i)
    {
        newMatObj.matrix[i].resize(newMatObj.nCols);
        for (int j = 0; j < newMatObj.nCols; ++j)
        {
            newMatObj.matrix[i][j] = matObj1.matrix[i][j] * matObj2.matrix[j][i];
        }
    }
    // add stuff here using multi-threading
    return newMatObj;
}

// print out matrix by overloading the << operator
inline std::ostream& operator<<(std::ostream& oss, const Matrix &matrixObj)
{
    for (int i = 0; i < matrixObj.nRows; i++)
    {
        for (int j = 0; j < matrixObj.nCols; j++)
        {
            oss << std::scientific << std::setw(12) << std::setprecision(3) << matrixObj.matrix[i][j]; // add the matrix to oss in the right format
        }
        oss << std::endl;
    }
    return oss;
}

#endif 

// should I put function members as private or public
// should I use vectors or arrays
// should my functions return a matrix (hence, what type should they be? )
// how do I use threading (use mutex?)
// overload operators

// what is the best ML algorithm to detect a phone in an image
// Does lthread make sense? or should it be lpthread?

// look up if pthread has functions for for loops
// use arrays instead of vectors
// consider return pointers and not the actual object
